#include <vector>
#include <list>
#include <algorithm>

/*
Функция должна удалить из списка lst элементы с номерами, заданными в
векторе v. Элементы списка нумеруются от 1. Номера элементов списка
отражают позиции элементов на момент начала работы программы. Если номер
повторяется в массиве более одного раза, все вхождения, кроме первого,
игнорируются. Если число в массиве не является допустимым номером
элемента в списке, оно игнорируется.
*/
void process(const std::vector<int>& v, std::list<int>& lst)
{
    size_t size = lst.size();
    std::vector<int> local_v;
    std::copy(std::begin(v), std::end(v), back_inserter(local_v));

    std::sort(std::begin(local_v), std::end(local_v));    
    auto v_it = std::unique(std::begin(local_v), std::end(local_v));
    local_v.erase(v_it, std::end(local_v));
    
    int steps = 0;
    auto l_it = std::begin(lst);
    for (auto i = std::begin(local_v); i != std::end(local_v); ++i)
    {
        if (*i >= 1 && *i <= size)
        {
            for (int j = 0; j < *i - 1 - steps; ++j)
            {
                ++l_it;
            }
            l_it = lst.erase(l_it);
            ++steps;
        }
    }
}   