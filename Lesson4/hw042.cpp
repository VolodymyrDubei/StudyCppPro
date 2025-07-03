#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

// Клас замовлення
class Order
{
  private:
    int id;
    std::vector<std::string> items;
    double totalPrice;
    std::string status;
   
  public:
    Order(int id, const std::vector<std::string>& items)
        : id(id), items(items), totalPrice(0.0), status("raw") {}

    int getId() const { return id; }

    std::vector<std::string> getItems() const
    {
      std::lock_guard<std::mutex> lock(mtx);
      return items;
    }

    void setTotalPrice(double price)
    {
      std::lock_guard<std::mutex> lock(mtx);
      totalPrice = price;
    }

    double getTotalPrice() const
    {
      std::lock_guard<std::mutex> lock(mtx);
      return totalPrice;
    }

    void setStatus(const std::string& st)
    {
      std::lock_guard<std::mutex> lock(mtx);
      status = st;
    }

    std::string getStatus() const
    {
      std::lock_guard<std::mutex> lock(mtx);
      return status;
    }


};

// Клас обробки замовлень
class OrderProcessor
{
  public:
    void validateOrders(std::vector<Order>& rawOrders)
    {
      for (auto& order : rawOrders)
      {
        if(order.getStatus() == "raw")
        {
          if (!order.getItems().empty())
          {
            order.setStatus("validated");
          } else 
          {
            order.setStatus("invalid");
          }
        }
      }
      
      std::cout << "Validation completed!\n" << std::endl; //Валідація завершена
    }

    void calculatePricing(std::vector<Order>& validOrders)
    {
      for (auto& order : validOrders)
      {
        while (order.getStatus() == "raw")
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        if (order.getStatus() == "validated")
        {
          double price = 0.0;
          
          for (const auto& item : order.getItems())
          {
            price += 10.0 + (item.length() % 5);
          }
          
          order.setTotalPrice(price);
          order.setStatus("priced");
        }
      }
      
      std::cout << "Price calculation completed!\n" << std::endl; //Розрахунок цін завершено
    }

    void checkInventory(std::vector<Order>& pricedOrders)
    {
      for (auto& order : pricedOrders)
      {
        // Чекаємо, поки замовлення буде пораховано
        while (order.getStatus() == "validated" || order.getStatus() == "raw")
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        if (order.getStatus() == "priced")
        {
          // Наприклад, всі замовлення з парним id є на складі
          if (order.getId() % 2 == 0)
          {
            order.setStatus("checked");
          } else
          {
            order.setStatus("out_of_stock");
          }
        }
      }
      
      std::cout << "Warehouse check completed!\n" << std::endl; //Перевірка складу завершена
    }

    void generateInvoices(std::vector<Order>& finalOrders)
    {
      for (auto& order : finalOrders)
      {
        // Чекаємо, поки замовлення буде перевірено на складі
        while (order.getStatus() == "priced" || order.getStatus() == "validated" || order.getStatus() == "raw")
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        
        if (order.getStatus() == "checked")
        {
          // Генерація і відправка рахунку
          std::cout << "Invoice for order #" << order.getId() << " for the amount $" << order.getTotalPrice() << ". Sent!\n" << std::endl;
          order.setStatus("invoiced");
        }
      }
      
      std::cout << "Invoice generation completed\n" << std::endl; //Генерація рахунків завершена
    }
};

int main()
{
  std::vector<Order> orders =
  {
    Order(1, {"apple", "banana"}),
    Order(2, {"milk"}),
    Order(3, {}),
    Order(4, {"bread", "cheese", "butter"}),
    Order(5, {"juice", "butter"}),
    Order(6, {"bread", "cheese", "butter", "juice"}),
    Order(7, {}),
    Order(8, {"apple", "banana", "juice"}),
    Order(9, {"milk", "juice"}),
    Order(10, {})
  };

  
  OrderProcessor processor;

  // Старт потоків
  std::thread t1(&OrderProcessor::validateOrders, &processor, std::ref(orders));
  std::thread t2(&OrderProcessor::calculatePricing, &processor, std::ref(orders));
  std::thread t3(&OrderProcessor::checkInventory, &processor, std::ref(orders));
  std::thread t4(&OrderProcessor::generateInvoices, &processor, std::ref(orders));

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "All orders processed!\n" << std::endl; //Усі замовлення оброблено

  return 0;
}
