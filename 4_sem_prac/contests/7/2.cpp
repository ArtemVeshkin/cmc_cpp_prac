#include <iostream>

/*
    Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
    eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim
    ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut
    aliquip ex ea commodo consequat. Duis aute irure dolor in
    reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla
    pariatur. Excepteur sint occaecat cupidatat non proident, sunt in
    culpa qui officia deserunt mollit anim id est laborum.
*/

class Result
{
    long long result_;
public:
    Result(long long result) : result_(result) {}

    long long result() const { return result_; }
};

void func(long long a, long long b, int k)
{
    if (!k) {
        throw Result{a + b};
    }

    try {
        if (b > 1) {
            func(a, b - 1, k);
        } else {
            throw Result{a};
        }
    } catch(Result ex) {
        if (b == 1) {
            throw ex;
        }
        b = ex.result();
    }

    try {
        func(a, b, k - 1);
    } catch(...) {
        throw;
    }
}

int main()
{
    long long a, b;
    int k;
    while (std::cin >> a >> b >> k)
    {
        try {
            func(a, b, k);
        } catch (Result ex) {
            std::cout << ex.result() << std::endl;
    }
    }
}