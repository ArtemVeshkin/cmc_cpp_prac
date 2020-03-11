#include <iostream>
#include <array>

int main()
{
    constexpr int SIZE = 10;
    std::array<int, SIZE> arr
    {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    int arr2[SIZE];

    // Контейнеры
    //    ||
    // Итераторы
    //    ||
    // Алгоритмы

    // Random Access Iterator - Итераторы произвольного доступа
    // Bidirectional Iterator - Можем ходить только вперед/назад
    // Input/Output Iterator  - Можем только читать/писать в итератор

    std::array<int, SIZE>::iterator i1 = arr.begin();
    std::array<int, SIZE>::const_iterator i2 = arr.cbegin();

    std::array<int, SIZE>::reverse_iterator i3 = arr.rbegin();
    std::array<int, SIZE>::const_reverse_iterator i4 = arr.crbegin();

    for (auto ii = arr.begin(); ii != arr.end(); ++ii)
    {
        std::cout << ++*ii << std::endl;
    }

    for (auto ii = arr.rbegin(); ii != arr.rend(); ++ii)
    {
        std::cout << *ii << std::endl;
    }

    std::array arr3{1, 2, 3}; // Автовывод типов (C++17)

    auto it = std::begin(arr);
    std::advance(it, 2); // Эффективный сдвиг итератора

    for (const auto &v : arr) // Range-based for
    {
        std::cout << v << std::endl;
    }
}