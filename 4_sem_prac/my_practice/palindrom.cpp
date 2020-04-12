#include <iostream>
#include <string>
#include <algorithm>

std::string get_palindrom(std::string s)
{
    std::string tmp;
    while (s != "")
    {
        tmp = s;
        std::reverse(tmp.begin(), tmp.end());
        if (s == tmp)
        {
            break;
        }
        s.pop_back();
    } 
    return s;
}

int main()
{
    std::string s;
    while (std::cin >> s)
    {
        std::cout << get_palindrom(s) << std::endl;
    }
    
    return 0;
}