#include <vector>
#include <list>
#include <algorithm>

void process(const std::vector<int>& v1, std::vector<int>& v2)
{
    int size = v2.size();
    std::vector<int> local_v(v1);

    std::sort(std::begin(local_v), std::end(local_v));
    auto v_it = std::unique(std::begin(local_v), std::end(local_v));
    local_v.erase(v_it, std::end(local_v));
    
    auto i1 = std::begin(v2);
    auto i2 = i1;
    auto cur = std::begin(local_v);
    while (cur != std::end(local_v) && *cur < 0)
    {
        ++cur;
    }
    int i;
    for (i = 0; i < size; ++i)
    {
        if (cur == std::end(local_v))
        {
            break;
        }
        if (i == *cur)
        {
            ++i1;
            ++cur;
            continue;
        }
        *i2 = *i1;
        ++i2;
        ++i1;
    }

    for (int j = i; j < size; ++j)
    {
        *i2 = *i1;
        ++i2;
        ++i1;
    }
    v2.erase(i2, v2.end());
}