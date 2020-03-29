class Sum
{
    int a_, b_;
public:
    Sum(int a, int b) : a_(a), b_(b) {}
    Sum(Sum sum, int val) : a_(sum.a_ + sum.b_), b_(val) {}

    int get() const
    {
        return a_ + b_;
    }
};