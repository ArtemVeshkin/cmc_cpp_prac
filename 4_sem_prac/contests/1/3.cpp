class Sub
{
    int a, b;
public:
    Sub(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    Sub(Sub sum, int val)
    {
        a = sum.a - sum.b;
        b = val;
    }
    Sub(int val, Sub sum)
    {
        a = val;
        b = sum.a - sum.b;
    }

    int value() const
    {
        return a - b;
    }
};