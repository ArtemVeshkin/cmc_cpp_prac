#include <iostream>

char c;
bool read()
{
    return static_cast<bool>(std::cin >> c);
}

bool A();
bool B();

bool S()
{
    if(!read()) {
        return false;
    }
    switch (c)
    {
        case 'a':
            return A() && read() && c == 'b';
            break;
        case 'c':
            return B();
            break;
        default:
            return false;
    }
}

bool A()
{
    if(!read()) {
        return false;
    }
    switch (c)
    {
        case 'c':
            return A() && read() && c == 'd';
            break;
        case 'e':
            return true;
            break;
        default:
            return false;
    }
}
bool B()
{
    if(!read()) {
        return true;
    }
    switch (c)
    {
        case 'b':
            return B();
            break;
        case 'd':
            return true;
            break;
        default:
            return false;
    }
}

int main()
{
    std::cout << (S() && !read()) << std::endl;
}