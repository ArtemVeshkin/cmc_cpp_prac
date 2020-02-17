#include <iostream>

class A
{
    int a;
    bool is_sum;
public:
    A()
    {
        std::cin >> a;
        is_sum = false;
    }
    A(A &val)
    {
        std::cin >> a;
        a += val.a;
        is_sum = true;
    }

    ~A()
    {
        if (is_sum)
        {
            std::cout << a << std::endl;
        }
    }
};