#include <iostream>
#include <vector>
#include <cstdint>

void process(std::vector<int64_t>& v, int64_t threshold)
{
    size_t size = v.size(), cnt{};
    for (size_t i = 0; i < size; ++i)
    {
        auto it = std::prev(std::end(v), i + 1 + cnt);
        if (*it >= threshold)
        {
            v.push_back(*it);
            ++cnt;
        }
    }
}
    