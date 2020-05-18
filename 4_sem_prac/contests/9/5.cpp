#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <utility>

int main()
{
    char lrule;
    std::string rrule;
    std::vector<std::pair<char, std::string>> rules;
    std::vector<bool> reached('Z' - 'A' + 1, false);

    reached['S' - 'A'] = true;

    while (std::cin >> lrule >> rrule)
    {
        rules.push_back({ lrule, /* --> */ rrule });
    }

    bool nothing_to_go = false;
    while (!nothing_to_go) {
        nothing_to_go = true;

        for (auto rule : rules)
        {
            if (reached[rule.first - 'A']) {
                for (auto c : rule.second)
                {
                    if (std::isupper(c)) {
                        nothing_to_go = nothing_to_go 
                                & reached[c - 'A']; 
                        reached[c - 'A'] = true;
                    }
                }
            }
        }
    }

    for (auto rule : rules)
    {
        if (reached[rule.first - 'A']) {
            std::cout << rule.first << " " << rule.second << std::endl;
        }
    }
}