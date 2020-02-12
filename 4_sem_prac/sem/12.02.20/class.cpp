// Наследование
;
class Random
{
public:
    int next(int n);
    Random() {};
};

class RandomRand : Random
{
    FILE *f_;
public:
    int next(int n)
    {
        // ...
    }
    RandomRand();
    ~RandomRand()
    {
        fclose(f_);
    }
};

class RandomDev : Random
{
    FILE *f_;
public:
    int next(int n)
    {
        // ...
    }
    RandomDev();
    ~RandomDev()
    {
        fclose(f_);
    }
};

// Динамический полиморфизм

class Random {
public:
    virtual int next(int n);
}

// Динамическая память

long *pl = new long(10);
delete[] pl;

// "Рабоче-крестьянский способ" (с) Шестимеров А.А.
std::vector<long> s(10);

std::array<long, 10> s;