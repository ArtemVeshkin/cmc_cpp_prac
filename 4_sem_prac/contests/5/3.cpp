#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

#include "include.h"

class Factory
{
    const std::map<char, std::function<Figure* (std::string)>> figures = {
        {'R', Rectangle::make},
        {'S', Square::make},
        {'C', Circle::make}
    };

public:
    Figure* make(std::string str) const
    {
        char type;
        std::string args;

        std::istringstream input{str};
        input >> type;
        std::getline(input, args);

        return figures.find(type)->second(args);
    }
};

Factory factory_instance()
{
    Factory f;
    return f
}

int main()
{
    std::vector<double> squares;

    std::string input;
    while(std::getline(std::cin, input))
    {
        
    }
}