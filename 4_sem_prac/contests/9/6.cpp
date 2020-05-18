#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

int main()
{
    std::map<std::pair<std::string, char>, std::string> f;
    std::string cur, next;
    char c;
    while (std::cin >> cur && cur != "END")
    {
        std::cin >> c >> next;
        f[{ cur, c }] = next;
    }

    std::vector<std::string> t_states;
    while (std::cin >> cur && cur != "END")
    {
        t_states.push_back(cur);
    }

    std::string str;
    std::cin >> cur >> str;

    for (size_t i = 0; i < str.size(); ++i)
    {
        // no rule found
        if (f.find({ cur, str[i] }) == f.end()) {
            std::cout << "0\n" << i << '\n' << cur << std::endl;
            return 0;
        }
        cur = f[{ cur, str[i] }];
    }

    bool found = false;
    for (auto state : t_states)
    {
        if (state == cur) {
            found = true;
        }
    }

    std::cout << found << '\n' << str.size() << '\n' << cur << std::endl;
}