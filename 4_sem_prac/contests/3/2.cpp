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
    
    auto i1 = v2.begin();
    auto i2 = i1;
    auto cur = local_v.begin();
    while (cur != local_v.end() && *cur < 0)
    {
        ++cur;
    }
    int i;
    for (i = 0; i < size; ++i)
    {
        if (cur == local_v.end())
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