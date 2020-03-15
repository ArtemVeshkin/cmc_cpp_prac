#include <iostream>
#include <vector>
#include <list>

/*
Функция проходит элементы вектора целых чисел с заданным шагом и
копирует их в последовательные элементы списка (список проходится с
шагом 1). Элементы вектора копируются "поверх" существующих элементов
списка, если соответствующие элементы существуют.
*/

void process(const std::vector<int>& v,
    std::list<int>& l, int h)
{
    auto l_it = std::begin(l);
    
    for (auto v_it = std::begin(v);
        v_it + h <= std::end(v) && l_it != std::end(l); v_it += h, ++l_it)
    {
        *l_it = *v_it;
    }

    for (auto it = std::rbegin(l); it != std::rend(l); ++it)
    {
        std::cout << *it << '\n';
    }
}