#include <iostream>


// Внешне не видно
namespace
{
int myfunc(int a, int b)
{
    return a + b;
}
}

namespace A
{
    namespace B
    {
    int myfunc(int a, int b)
    {
        return a + b;
    }
    }
int myfunc(int a, int b)
{
    return a + b;
}
}

// ---
namespace A::B
{
    int myfunc(int a, int b);
}

int A::B::myfunc(int a, int b)
{
    return a + b;
}

// Класс включает в себя понятие namespace

int main()
{
    std::cout << myfunc(1, 2);
    // Если myfunc() вне namespace, можно так:
    std::cout << ::myfunc(1, 2);

    std::cout << A::myfunc(1, 2);
    std::cout << A::B::myfunc(1, 2);
}