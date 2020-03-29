#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double sum = 0;
    double ma2 = 0;
    long long n = 0;
    double x;
    while (std::cin >> x) {
        ++n;
        sum += x;
        ma2 += x * x;
    }

    std::cout << std::setprecision(10) << sum / n << 
    std::endl << sqrt(ma2 / n - sum * sum / (n * n)) << std::endl;
}