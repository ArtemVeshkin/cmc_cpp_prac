#include <iostream>
#include <string>

int main()
{
    bool ks = true, nc = true, left_s = false, right_s = false,
            term = false, s_to_eps = false;

    std::string lrule, rrule;
    while (std::cin >> lrule >> rrule)
    {
        if (lrule == "S") {
            left_s = true;

            if (rrule == "_") {
                s_to_eps = true;
            }
        } else if (rrule == "_" || lrule.size() > rrule.size()) {
            nc = false;
        }

        bool found_up = false;
        for (auto c : lrule) {
            if (std::isupper(c)) {
                found_up = true;
            }
        }
        if (!found_up) {
            term = true;
        }

        bool found_s = false;
        for (auto c : rrule) {
            if (c == 'S') {
                found_s = true;
            }
        }
        if (found_s) {
            right_s = true;
        }

        if (1 < lrule.size()) {
            ks = false;
        }
    }

    if (s_to_eps && right_s) {
        nc = false;
    }

    if (term || !left_s) {
        std::cout << "-1\n";
    } else if (ks) {
        if (nc) {
            std::cout << "23\n";
        } else {
            std::cout << "2\n";
        }
    } else {
        std::cout << "10\n";
    }
}