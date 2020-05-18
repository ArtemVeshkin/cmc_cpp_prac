/*
    Тип 1
    L(G) = {a^n 0^m b^n 1^m, n > 0, m > 0}
    G:
        S   --> aAB
        aAB --> aaABB
        aA  --> a0AC  | a0C
        0AC --> 00ACC | 00CC
        CB  --> CD
        CD  --> BD
        BD  --> BC
        0B  --> 0b
        bB  --> Bb
        C   --> 1
*/

#include <iostream>
#include <string>

bool check_word(std::string str)
{
    int n{}, m{}, len = static_cast<int>(str.size());

    for (int i = 0; i < len; ++i)
    {
        if (str[i] != 'a') {
            break;
        }
        ++n;
    }

    for (int i = n; i < len; ++i)
    {
        if (str[i] != '0') {
            break;
        }
        ++m;
    }

    if (!m || !n || len != 2 * n + 2 * m) {
        return false;
    }

    int cur_n = n;
    for (int i = m + n; i < len; ++i)
    {
        if (str[i] != 'b' || i == len - 1) {
            if (cur_n) {
                return false;
            }
            break;
        }
        --cur_n;
    }

    for (int i = 2 * n + m; i < len; ++i)
    {
        if (str[i] != '1') {
            if (m) {
                return false;
            }
        }
        --m;
    }
    
    return true;
}

int main()
{
    std::string str;
    while (std::cin >> str)
    {
        std::cout << check_word(str) << std::endl;
    }
}