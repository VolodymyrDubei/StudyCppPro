#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

using namespace std;

// Шаблонна функція для виводу елементів контейнера за допомогою range-based loop
template <typename Container>
void printContRangeLoop(const Container& container)
{
    for (const auto& element : container)
    {
        cout << element << ' ';
    }
    cout << endl;
}


// Шаблонна функція для виводу елементів контейнера за допомогою ітераторів
template <typename Container>
void printContIterator(const Container& container)
{
    for (auto it = container.begin(); it != container.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main() 
{
    std::vector<int> contVector = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<std::string> contList = {"Hello", "World", "C++ Pro"};
    std::set<double> contSet = {43.17, 25.77, 51.31, 98.35, 37.21};

    cout << "Outputting container elements using range-based loop!" << endl;
    printContRangeLoop(contVector);
    printContRangeLoop(contList);
    printContRangeLoop(contSet);

    cout << endl;

    cout << "Outputting container elements using iterators!" << endl;
    printContIterator(contVector);
    printContIterator(contList);
    printContIterator(contSet);

    return 0;
}