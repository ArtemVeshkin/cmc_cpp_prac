#include <iostream>
#include <string>

class Reverser
{
    std::string data_;
public:
    Reverser()
    {
        if (!(std::cin >> data_))
        {
            throw 1;
        }
    }

    ~Reverser()
    {
        std::cout << data_ << std::endl;
    }
};

void process()
{
    Reverser r;
    try {
        process();
    } catch(...) {
        throw;
    } 
}

int main()
{
    try {
        process();
    } catch(...) {}
}