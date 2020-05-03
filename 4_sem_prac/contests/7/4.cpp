#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

void touring_machine(std::string& input,
        const std::map<std::pair<char, char>, std::vector<char>>& rules)
{
    char state = 'S';
    int pos{};

    while(true)
    {
        auto cur_rule = rules.find({state, input[pos]});
        if (cur_rule != rules.end()) {
            int action{};
            switch(cur_rule->second[2]) {
                case 'L': action = -1; break;
                case 'R': action =  1; break;
                case 'S': action =  0; break;
            }

            if (action == 0
                    && cur_rule->first.first == cur_rule->second[0]) {
                return;
            }

            input[pos] = cur_rule->second[1];
            pos       += action;
            state      = cur_rule->second[0];
        } else {
            return;
        }
    }
}

int main()
{
    std::map<std::pair<char, char>, std::vector<char>> rules = {
        {{'S', '0'}, {'S', '0', 'R'}},
        {{'S', '1'}, {'A', '1', 'R'}},
        {{'S', '#'}, {'S', '#', 'R'}},
        {{'A', '0'}, {'A', '0', 'R'}},
        {{'A', '1'}, {'S', '1', 'R'}},
        {{'A', '#'}, {'B', '#', 'L'}},
        {{'B', '0'}, {'B', '0', 'L'}},
        {{'B', '1'}, {'B', '1', 'L'}},
        {{'B', '#'}, {'C', '#', 'R'}},
        {{'C', '0'}, {'C', '0', 'R'}},
        {{'C', '1'}, {'D', '0', 'S'}},
        {{'D', '0'}, {'D', '0', 'S'}}
    };

    std::string input;
    std::cin >> input;

    touring_machine(input, rules);

    std::cout << input << std::endl;
}