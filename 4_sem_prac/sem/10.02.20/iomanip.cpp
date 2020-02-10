#include <iostream>
#include <iomanip>

int main(int argc, const char *argv[])
{
    char c;

    // Страшно, но нужно так
    std::cout << std::hex << std::setw(10) << \
    std::setfill('0') << c << std::dec << c << std::endl;

    printf("%010;x %ld\n", c, c);

}