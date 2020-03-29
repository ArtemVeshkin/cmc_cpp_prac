#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char const *argv[])
{
    numbers::complex c{std::string(argv[1])}, result;
    std::stringstream sstream;
    sstream << argv[2] << ' ' << argv[3];
    double r;
    int n;
    sstream >> r >> n;

    std::vector<std::string> args;
    for (int i = 4; argv[i]; ++i) {
        args.push_back(argv[i]);
    }
    
    double pi = acos(-1);
    double d = 2 * pi / n;
    for (int i = 0; i < n; ++i) {
        double angle = i * d;
        numbers::complex dl{-sin(angle) * d, cos(angle) * d};
        result += numbers::eval(args, c + numbers::complex(
            r * cos(angle), r * sin(angle))) * dl;
    }
    std::cout << result.to_string() << std::endl;
}