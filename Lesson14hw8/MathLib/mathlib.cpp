#include <iostream>
#include "mathlib.h"


// Реалізація функцій

// додавання

double add(double a, double b) {
    return a + b;
}


// віднімання

double subtract(double a, double b) {
    return a - b;
}


// множення

double multiply(double a, double b) {
    return a * b;
}


// ділення

double divide(double a, double b) {
    if ( b == 0) {
        std::cout << "Attention! Division by zero!" << std::endl;
        return 0;
    }

    return a / b;
}


// піднесення до степеня

double power(double base, int exponent) {
    double result = 1;
    bool negative = false;

    if (exponent < 0) {
        negative = true;
        exponent = -exponent;
    }

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    if (negative) {
        result = 1.0 / result;
    }

    return result;
}


// квадратний корінь

double squareRoot(double value) {
    if (value < 0) {
        std::cout << "Attention! Square root of a negative number!" << std::endl; // Квадратний корінь з від’ємного числа не визначено
        return 0;
    }

    if (value == 0) return 0;

    double x = value;
    double eps = 1e-10; // Точність

    while (true) {
        double next = 0.5 * (x + value / x);
        if (fabs(x - next) < eps) break;
        x = next;
    }

    return x;
}


// абсолютне значення

double absoluteValue(double value) {
    if (value < 0)
        return -value;
    else
        return value;
}


// факторіал числа

int factorial(int n) {
    if (n < 0) {
        std::cout << "Attention! The factorial for negative numbers is not defined!" << std::endl; // Факторіал для від’ємних чисел не визначений
        return 0;
    }

    int result = 1;

    for (int i = 2; i <= n; ++i) {
        result *= i;
    }

    return result;
}


// перевірка чи число просте

bool isPrime(int number) {
    if (number <= 1)
        return false;

    if (number == 2)
        return true;

    if (number % 2 == 0)
        return false;

    for (int i = 3; (i * i) <= number; i += 2) {
        if (number % i == 0)
            return false;
    }

    return true;
}


// найбільший спільний дільник

int gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


// максимум масиву

double findMax(const double arr[], int size) {
    if (size <= 0) {
        std::cout << "Attention! Array size is incorrect!" << std::endl; // Розмір масиву некоректний
        return 0;
    }

    double maxValue = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    return maxValue;
}


// мінімум масиву

double findMin(const double arr[], int size) {
    if (size <= 0) {
        std::cout << "Attention! Array size is incorrect!" << std::endl; // Розмір масиву некоректний
        return 0;
    }

    double minValue = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }

    return minValue;
}


// сума елементів

double calculateSum(const double arr[], int size) {
    if (size <= 0) {
        std::cout << "Attention! Array size is incorrect!" << std::endl; // Розмір масиву некоректний
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}


// середнє арифметичне

double calculateAverage(const double arr[], int size) {
    if (size <= 0) {
        std::cout << "Attention! Array size is incorrect!" << std::endl; // Розмір масиву некоректний
        return 0;
    }

    double sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum / size;
}


// сортування масиву

void sortArray(double arr[], int size) {
    if (size <= 0) {
        std::cout << "Attention! Array size is incorrect!" << std::endl; // Розмір масиву некоректний
    }
    else {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    double temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}


// перевірка на парність

bool isEven(int number) {
    return (number % 2) == 0;
}


// перевірка на непарність

bool isOdd(int number) {
      return (number % 2) != 0;
}


// n-те число Фібоначчі

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
