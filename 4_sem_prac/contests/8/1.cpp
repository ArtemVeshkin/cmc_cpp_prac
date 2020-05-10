#include <iostream>
#include <string>

int main()
{
    std::string str;

    while (std::cin >> str)
    {
        [[maybe_unused]]
        char state = 'a', prev_state = 'a';
        for (size_t i = 0; i < str.size(); ++i)
        {
            prev_state = state;
            if (str[i] == '3' || str[i] == '4') {
                state = 'a';
            } else if (str[i] == '1' || str[i] == '2') {
                state = 'b';
            } else {
                std::cout << "0\n";
                goto next_word; 
            }

            if (prev_state == 'b' && state == 'a') {
                std::cout << "0\n";
                goto next_word;
            }
        }

        std::cout << "1\n";
        next_word:;
    }
}