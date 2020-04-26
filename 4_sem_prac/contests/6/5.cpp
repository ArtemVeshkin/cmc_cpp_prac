#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <complex>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<T>>
    quadratic(std::array<T, 3> v)
    {
        if (!std::norm(v[2] - T{})) {
            if (!std::norm(v[1] - T{})) {
                if (!std::norm(v[0] - T{})) {
                    return { false, std::vector<T>{} };
                } else {
                    return { true,  std::vector<T>{} };
                }
            } else {
                return { true, std::vector<T>{-v[0] / v[1]} };
            }
        } else {
            T d = std::sqrt(v[1] * v[1] - T{4} * v[0] * v[2]);
            return { true, std::vector<T> { 
                    (-v[1] + d) / (T{2} * v[2]),
                    (-v[1] - d) / (T{2} * v[2]) } };
        }
    }
}