#include <iostream>
#include <vector>
#include <cmath>
#include <future>

// Простий пул потоків
class SimpleThreadPool
{
  private:
	  std::vector<std::thread> threads;

  public:
	  explicit SimpleThreadPool(size_t numThreads)
    {
		  threads.reserve(numThreads);
	  }

	  template<typename Function, typename... Args>
	  void calculation(Function&& func, Args&&... args)
    {
		  threads.emplace_back(std::forward<Function>(func),
			  std::forward<Args>(args)...);
	  }

	  ~SimpleThreadPool()
    {
      for (auto& t : threads)
      {
			  if (t.joinable())
        {
				  t.join();
			  }
		  }
		  threads.clear();
	  }
};

// Факторіал
void factorial(int value)
{
  unsigned long long result = 1;
  
  for (int i = 2; i <= value; i++)
    result *= i;
  
  std::cout << "Result factorial: " << result << std::endl;
}

// Сума квадратів
void sum_of_squares(int from, int to)
{
  unsigned long long sum = 0;
  for (int i = from; i <= to; i++)
    sum += i * i;
  
  std::cout << "Result sum_of_squares: " << sum << std::endl;
}

// Фібоначчі до n-го елемента
void fibonacci(int n)
{
    std::vector<unsigned long long> fib(n);
    
    if (n > 0) fib[0] = 0;
    if (n > 1) fib[1] = 1;
  
    for (int i = 2; i < n; ++i)
      fib[i] = fib[i - 1] + fib[i - 2];
 
  std::cout << "Result fibonacci: ";
  for (auto res : fib) std::cout << res << " ";
  std::cout << std::endl;
}

// Прості числа до max
void primes(int max)
{
    std::vector<int> vprimes;

    for (int i = 2; i <= max; ++i)
    {
        bool is_prime = true;
        for (int j = 2; j <= std::sqrt(i); ++j)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            vprimes.push_back(i);
    }

  std::cout << "Result primes: ";
  for (auto res : vprimes) std::cout << res << " ";
  std::cout << std::endl;

}



int main()
{
    SimpleThreadPool pool(4); // створюємо пул з 4 потоків

    pool.calculation(factorial, 15);
    pool.calculation(sum_of_squares, 1, 1000);
    pool.calculation(fibonacci, 30);
    pool.calculation(primes, 100);

    return 0;
}








