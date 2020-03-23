#include <iterator>

template <typename Container>
typename Container::value_type process(const Container a)
{
    auto it = a.rbegin();
    if (a.size() >= 5)
    {
        return *it + *std::next(it, 2) + *std::next(it, 4);
    } else if (a.size() >= 3)
    {
        return *it + *std::next(it, 2);
    } else if (!a.empty()) {
        return *it;
    }
    typename Container::value_type dflt{};
    return dflt;
}