#include <vector>
#include <iterator>
#include <functional>

template <typename Iterator, typename Function>
void myapply(Iterator begin, Iterator end, Function func)
{
    while (begin != end)
    {
        func(*begin);
        ++begin;
    }
}

template <typename Iterator, typename Function>
std::vector<std::reference_wrapper
        <typename std::iterator_traits<Iterator>::value_type>>
myfilter2(Iterator begin, Iterator end, Function func)
{
    std::vector<std::reference_wrapper
        <typename std::iterator_traits<Iterator>::value_type>> res;

    while (begin != end)
    {
        if (func(*begin))
        {
            res.push_back(*begin);
        }
        ++begin;
    }

    return res;
}