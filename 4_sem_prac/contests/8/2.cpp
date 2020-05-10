#include <iostream>
#include <string>

int main()
{
    char c = '0', prev_c = ' ';
    int k{}, m{}, cur_k{}, cur_m{};
    bool belongs = true, first_time = true, fresh = false;
    while ((c = getchar()) != EOF)
    {
        // New word
        if (isspace(static_cast<unsigned char>(c))) {
            if (!(isspace(static_cast<unsigned char>(prev_c)))) {
                if (k == 0 || m == 0) {
                    belongs = false;
                }
                if (cur_k != k || cur_m != m) {
                    belongs = false;
                }

                std::cout << belongs << "\n";
                fresh = false;
                k = 0; m = 0;
                cur_k = 0; cur_m = 0;
                belongs = true; first_time = true;
            }
        } else {
            // "0"
            if (c == '0') {
                fresh = true;
                if (m == 0) {
                    ++k;
                    ++cur_k;
                } else {
                    first_time = false;

                    if (prev_c == '1') {
                        if (cur_k != k || cur_m != m) {
                            belongs = false;
                        }

                        cur_k = 1;
                        cur_m = 0;
                    } else {
                        ++cur_k;
                    }
                }

            // "1"
            } else if (c == '1') {
                fresh = true;
                if (first_time) {
                    ++m;
                }
                ++cur_m;
            } else {
                belongs = false;
            }
        }
        prev_c = c;
    }

    if (fresh) {
        if (k == 0 || m == 0) {
            belongs = false;
        }
        if (cur_k != k || cur_m != m) {
            belongs = false;
        }

        std::cout << belongs << "\n";
    }
}