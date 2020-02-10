#include <iostream>

int myfunc(int a, int b)
{
    return a + b;
}

auto func(auto a, auto b)
{
    return a + b;
}

int main()
{
    // lambda
    auto func = [](int a, int b) {
        return a + b;
    };
    // Можно использовать в некоторых ситуациях

    // auto уместно, когда улучшает читаемость программы

    // Так нельзя
    auto a;
    // Так можно, но не стоит
    auto a = 0;
    // Норм
    auto b = a;

    int a, b;
    std::cin >> a >> b;
    std::cout << func(a, b) << std::endl;
}