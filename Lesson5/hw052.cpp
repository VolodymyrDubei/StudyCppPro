#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <mutex>
#include <atomic>
#include <chrono>

class SafeBankAccount
{
  private:
    double balance = 1000.0;
    mutable std::mutex balance_mutex;

  public:
    void deposit(double amount)
    {
      std::lock_guard<std::mutex> lock(balance_mutex);
      balance += amount;
    }

    bool withdraw(double amount)
    {
      std::lock_guard<std::mutex> lock(balance_mutex);
      if (balance >= amount)
      {
        balance -= amount;
        return true;
      }
      
      return false;
    }

    double get_balance() const
    {
      std::lock_guard<std::mutex> lock(balance_mutex);
      return balance;
    }
};

class SafeBankStatistics
{
  private:
    std::atomic<int> transaction_count{0};
    std::atomic<double> total_amount{0.0};
    mutable std::mutex stat_mutex;

  public:
    void record_transaction(double amount)
    {
      transaction_count.fetch_add(1, std::memory_order_relaxed);
      std::lock_guard<std::mutex> lock(stat_mutex);
      total_amount = total_amount + amount;
    }

    int get_total_transactions() const
    {
      return transaction_count.load(std::memory_order_relaxed);
    }

    double get_total_amount() const
    {
      std::lock_guard<std::mutex> lock(stat_mutex);
      return total_amount;
    }
};

void cashier_work(SafeBankAccount& account, SafeBankStatistics& stats, int operations_count, int cashier_id)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> deposit_dist(50, 500);
    std::uniform_int_distribution<> withdraw_dist(10, 200);
    std::uniform_int_distribution<> op_type(0, 1); // 0 - deposit, 1 - withdraw

  for (int i = 0; i < operations_count; ++i)
  {
    int op = op_type(gen);
        
    if (op == 0)  // deposit
    {
      double amount = deposit_dist(gen);
      account.deposit(amount);
      stats.record_transaction(amount);
    }
    else  // withdraw
    {
      double amount = withdraw_dist(gen);
            
      if (account.withdraw(amount))
      {
        stats.record_transaction(-amount);
      }
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

int main()
{
  SafeBankAccount account;
  SafeBankStatistics stats;

  const int cashier_count = 5;
  const int operations_per_cashier = 100;

  std::cout << "=== Bank Simulation Results ===" << std::endl;
  std::cout << "Initial balance: " << account.get_balance() << std::endl;

  std::vector<std::thread> cashiers;

  for (int i = 0; i < cashier_count; ++i)
  {
    cashiers.emplace_back(cashier_work, std::ref(account), std::ref(stats), operations_per_cashier, i);
  }

  for (auto& t : cashiers)
  {
    t.join();
  }

  std::cout << "Final balance: " << account.get_balance() << std::endl;
  std::cout << "Total transactions: " << stats.get_total_transactions() << std::endl;
  std::cout << "Total transaction amount: " << stats.get_total_amount() << std::endl;
  std::cout << "All cashiers completed work safely!" << std::endl;

  return 0;
}
