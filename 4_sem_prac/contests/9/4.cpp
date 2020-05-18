/*
    G:
        S --> aAd
        A --> aAd | bBc
        B --> bYc | ε
*/

#include <iostream>

void A(int n, int m);
void B(int m);

void S(int n, int m)
{
    std::cout << 'a';
    A(n - 1, m);
    std::cout << 'd' << std::endl;
}

void A(int n, int m)
{
    if (n > 0) {
        std::cout << 'a';
        A(n - 1, m);
        std::cout << 'd';
    } else {
        std::cout << 'b';
        B(m - 1);
        std::cout << 'c';
    }
}

void B(int m)
{
    if (m > 0) {
        std::cout << 'b';
        B(m - 1);
        std::cout << 'c';
    }
}

int main()
{
    int k;
    std::cin >> k;

    if (k % 2 == 0 && k > 3) {
        for (int i = k / 2 - 1; i > 0; --i)
        {
            S(i, k / 2 - i);
        }
    }
}