class Sub
{
    int a_, b_;
public:
    Sub(int a, int b) : a_(a), b_(b) {}

    Sub(Sub sum, int val) : a_(sum.a_ - sum.b_), b_(val) {}
    
    Sub(int val, Sub sum) : a_(val), b_(sum.a_ - sum.b_) {}

    int value() const
    {
        return a_ - b_;
    }
};