class Sum
{
    int a, b;
public:
    Sum(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    Sum(Sum sum, int val)
    {
        a = sum.a + sum.b;
        b = val;
    }

    int get() const
    {
        return a + b;
    }
};