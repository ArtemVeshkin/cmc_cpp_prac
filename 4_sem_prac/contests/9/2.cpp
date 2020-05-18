#include <iostream>
#include <string>

enum states { H, A, D, E, F, G, K, I, J, ER };

states next_state(states first, states second, char c)
{
    if (c == '0') {
        return first;
    } else if (c == '1') {
        return second;
    }
    return ER;
}

bool check_word(std::string str)
{
    states cur_state = H;

    for (size_t i = 0; i < str.size(); ++i)
    {
        switch (cur_state)
        {
            case H:
                cur_state = next_state(A, D, str[i]);
                break;
            case A:
                cur_state = next_state(A, D, str[i]);
                break;
            case D:
                cur_state = next_state(E, F, str[i]);
                break;
            case E:
                cur_state = next_state(G, K, str[i]);
                break;
            case F:
                cur_state = next_state(I, J, str[i]);
                break;
            case G:
                cur_state = next_state(A, D, str[i]);
                break;
            case K:
                cur_state = next_state(E, F, str[i]);
                break;
            case I:
                cur_state = next_state(G, K, str[i]);
                break;
            case J:
                cur_state = next_state(I, J, str[i]);
                break;
            default:
                cur_state = ER;
        }
    }

    return cur_state == G || cur_state == K
            || cur_state == I || cur_state == J;
}

int main()
{
    std::string str;
    while (std::cin >> str)
    {
        std::cout << check_word(str) << std::endl;
    }
}