#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> contVector = {1, 2, 3, 4, 5};

    auto increaseElements = [&contVector](int value)
    {
        for (auto& element : contVector)
        {
            element += value;
        }
    };

    increaseElements(10);

    for (const auto& element : contVector)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
