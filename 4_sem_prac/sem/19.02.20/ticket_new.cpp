#include <string>

class Station;

class Ticket
{
    char *barCode;
public:
    Ticket(const Station &from, Station &to)
    {
        barCode = new char[256];
        /* Не стоит выделять память в конструкторе,
           тк при ошибке внутри конструктора 
           объект не будет создан и деструктор не
           вызовется и произойдет утечка памяти*/
    }
    bool reserve();
    std::string getBarCode();
    ~Ticket()
    {
        delete [] barCode;
    }
};