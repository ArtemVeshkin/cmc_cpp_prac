#include <iostream>
#include <vector>

void process(std::vector<uint64_t>& v, uint32_t s)
{
    uint64_t cur_sum{};
    uint32_t cur_shift{};
    std::vector<uint64_t> v_c(v);

    v.resize(v.size() + v.size() / s);
    auto v_it = v.begin();
    auto v_c_it = v_c.begin();

    while (v_it != v.end())
    {
        if (cur_shift != s) {
            *v_it = *v_c_it;
            cur_sum += *v_c_it;

            ++cur_shift;
            ++v_it;
            ++v_c_it;
        } else {
            *v_it = cur_sum;
            
            cur_shift = 0;
            ++v_it;
        }
    }
}