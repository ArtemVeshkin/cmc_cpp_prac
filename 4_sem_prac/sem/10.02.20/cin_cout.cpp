#include <iostream>

// #include <stdint.h>
#include <cstdint>

int main(int argc, const char *argv[])
{
    int32_t a, b;

    (std::cin >> a) >> b;

    // Подход ООП
    // std::cin.operator>>(a).operator>>(b);
    // ~ (std::cin >> a) >> b;

    ((std::cout << a) << " " << b) << std::endl;

    // Подход ООП
    // std::cout.operator<<(a).operator<<(" ").operator<<(b).operator<<(std::endl);
    // ~ ((std::cout << a) << " " << b) << std::endl;
}