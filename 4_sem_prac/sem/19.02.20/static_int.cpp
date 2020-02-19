#include <iostream>

class Ticket
{
    static int totalCount;
public:
    Ticket()
    {
        ++totalCount;
    }
    ~Ticket()
    {
        --totalCount;
    }
    void printTotal()
    {
        std::cout << totalCount << std::endl;
    }
};

int Ticket::totalCount = 0;// global

int main()
{
    Ticket mas[5];
    mas[0].printTotal();
    // Выведет 5
}