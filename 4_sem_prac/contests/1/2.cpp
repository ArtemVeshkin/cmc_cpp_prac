#include <iostream>

class A
{
    int a;
    bool is_sum;
public:
    A() : is_sum(false)
    {
        std::cin >> a;
    }
    A(const A& val) : is_sum(true)
    {
        std::cin >> a;
        a += val.a;
    }

    ~A()
    {
        if (is_sum) {
            std::cout << a << std::endl;
        }
    }
};