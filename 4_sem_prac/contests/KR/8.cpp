#include <iostream>
#include <string>

std::string gen_power(uint32_t power)
{
    std::string poliz;
    if (!power) {
        poliz = "1";
    } else {
        for (uint32_t i = 0; i < power; ++i)
        {
            poliz.push_back('x');
        }

        for (uint32_t i = 0; i < power - 1; ++i)
        {
            poliz.push_back('*');
        }
    }
    
    return poliz;
}