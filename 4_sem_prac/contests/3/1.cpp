#include <iostream>
#include <vector>
#include <cstdint>

void process(const std::vector<uint64_t>& v,
    std::vector<uint64_t>& v2, int h)
{
    auto v2_it = std::rbegin(v2);
    
    for (auto v_it = std::begin(v);
            v_it < std::end(v) && v2_it != std::rend(v2); v_it += h, ++v2_it) {
        *v2_it += *v_it;
        if (std::distance(v_it, std::end(v)) < h) {
            break;
        }
    }
}