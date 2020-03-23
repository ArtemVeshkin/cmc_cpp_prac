#include <algorithm>
#include <set>
#include <iterator>

template<typename It1, typename It2>
It2 myremove(It1 begin1, It1 end1,
    It2 begin2, It2 end2)
{
    std::set<int> idxs;
    idxs.insert(begin1, end1);

    auto idxs_it =  idxs.begin();
    while (true)
    {
        if (idxs_it == idxs.end() || *idxs_it >= 0)
        {
            break;
        }
        ++idxs_it;
    }

    It2 end;
    int idx{};
    if (idxs_it != idxs.end())
    {
        for (end = begin2; begin2 != end2; ++begin2, ++idx)
        {
            if (idxs_it != idxs.end() && idx == *idxs_it)
            {
                ++idxs_it;
            } else {
                std::iter_swap(end, begin2);
                ++end;
            }
        }
    } else {
        end = end2;
    }
    
    return end;
}