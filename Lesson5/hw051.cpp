#include <iostream>
#include <thread>
#include <vector>
#include <random>


class UnsafeBankAccount
{
  private:
    double balance = 1000.0;

  public:
    void deposit(double amount)
    {
      balance += amount;
    }

    bool withdraw(double amount)
    {
      if (balance >= amount)
        {
          balance -= amount;
          return true;
        }
      return false;
    }

    double get_balance() const
    {
      return balance;
    }
};

class UnsafeBankStatistics
{
  private:
    int transaction_count = 0;
    double total_amount = 0.0;

  public:
    void record_transaction(double amount)
    {
      transaction_count++;
      total_amount += amount;
    }

    int get_total_transactions() const { return transaction_count; }
    double get_total_amount() const { return total_amount; }
};

void cashier_work(UnsafeBankAccount& account, UnsafeBankStatistics& stats, int operations_count, int cashier_id)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> deposit_dist(50, 500);
  std::uniform_int_distribution<> withdraw_dist(10, 200);
  std::uniform_int_distribution<> op_type(0, 1); // 0 - deposit, 1 - withdraw


  for (int i = 0; i < operations_count; ++i)
  {
    int operation = op_type(gen);
      
    if (operation == 0) // deposit
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
      } else
      {
        // withdrawal failed, no transaction!
      }
    }
  }
}

int main()
{
  UnsafeBankAccount account;
  UnsafeBankStatistics stats;

  const int cashier_count = 5;
  const int operations_per_cashier = 50;

  std::vector<std::thread> cashiers;

  std::cout << "=== Bank Simulation Results ===" << std::endl;
  std::cout << "Initial balance: " << account.get_balance() << std::endl;

  for (int i = 0; i < cashier_count; ++i)
  {
    cashiers.emplace_back(cashier_work, std::ref(account), std::ref(stats), operations_per_cashier, i);
  }

  for (auto& cashier : cashiers)
  {
    cashier.join();
  }

  std::cout << "Final balance: " << account.get_balance() << std::endl;
  std::cout << "Total transactions: " << stats.get_total_transactions() << std::endl;
  std::cout << "Total transaction amount: " << stats.get_total_amount() << std::endl;
  std::cout << "All cashiers completed work safely!" << std::endl;

  return 0;
}
