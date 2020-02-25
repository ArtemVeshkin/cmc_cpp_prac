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
    auto v_it = begin(v);
    auto l_it = begin(l);
    auto l_end = end(l);

    while (true)
    {
        if (h <= end(v) - v_it)
        {
            if (l_it != l_end)
            {
                *l_it = *v_it;
                ++l_it;
            }
            v_it += h;
        } else {
            break;
        }
    }
    for (auto i = begin(l); i != l_end; ++i)
    {
        std::cout << *i << std::endl;
    }
}