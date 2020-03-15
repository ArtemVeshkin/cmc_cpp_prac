#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Sum {
    Sum() { sum = 0; }
    void operator()(double n) 
    {
        sum += n;
    }
 
    double sum;
};
 
int main()
{
    std::vector<double> v;
    double x;
    while (std::cin >> x)
    {
        v.push_back(x);
    }

    size_t shift = v.size() / 10;
    auto v_begin = v.begin() + shift;
    auto v_end = v.end() - shift;
    std::sort(v_begin, v_end);

    size_t new_size = v_end - v_begin;
    shift = new_size / 10;
    v_begin += shift;
    v_end -= shift;

    Sum s = std::for_each(v_begin, v_end, Sum());

    std::cout << std::fixed << std::setprecision(10)
        << s.sum / static_cast<double>(v_end - v_begin) << std::endl;
}