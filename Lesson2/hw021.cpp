#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class BigData
{
private:
  int* data;
  size_t size;

public:
  BigData(size_t size)
    {
      cout << "Construct" << endl;
      this->size = size;
		  data = new int[this->size];      
    };

  ~BigData()
    {
      cout << "Destruct" << endl;
      delete[] data;
    };

// Конструктор копіювання
  BigData(const BigData& other)
    {
      cout << "Copy construct" << endl;
      
      delete[] data;
      
      data = new int[other.size];

      for(size_t i = 0; i < other.size; i++)
      {
        this->data[i] = other.data[i];
      }

      this->size = other.size;
    };

// Оператор копіювання
  BigData& operator=(const BigData& other)
    {
      cout << "Copy operator" << endl;

      if (this == &other) return *this;

      delete[] data;

      data = new int[other.size];

      for(size_t i = 0; i < other.size; i++)
      {
        this->data[i] = other.data[i];
      }

      this->size = other.size;

      return *this;
    };

// Конструктор переміщення
  BigData(BigData&& other) noexcept
    {
      cout << "Move construct" << endl;

		  this->data = other.data;
		  this->size = other.size;

		  other.data = nullptr;
		  other.size = 0;
    };

// Оператор переміщення
  BigData& operator=(BigData&& other) noexcept
    {
      cout << "Move operator" << endl;

      if (this == &other) return *this;

      delete[] data;

      this->data = other.data;
		  this->size = other.size;

		  other.data = nullptr;
		  other.size = 0;

      return *this;
    };

// Функція сеттера
  void setData(size_t index, int value)
  {
    if (index < size)
    {
      data[index] = value;
    }
  }

// Функція виводу
  void print() const
  {
    cout << "BigData contains (size = " << size << "): ";

    for (size_t i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
  }
};

// Функція, яка створює та повертає обєкт BigData(за значенням)
BigData createdBigData(size_t size)
{
    BigData temp(size);

    for (size_t i = 0; i < size; ++i)
    {
        temp.setData(i, (i*2));
    }
    return temp;
}



int main()
{
    BigData a = createdBigData(5);
    a.print();

    BigData c(3);
    c.print();

    c = std::move(a);
    c.print();

    a.print();

    BigData b(3);
    b = createdBigData(10);
    b.print();

    return 0;
}
