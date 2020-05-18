#include <iostream>

class Figure{
public:
    Figure() {};

    virtual ~Figure() {};

    virtual bool equals(Figure * other) const = 0;
};

class Rectangle : public Figure {
    int a_, b_;
public:
    Rectangle(int a = 0, int b = 0) : a_(a), b_(b) {}

    virtual ~Rectangle() {}

    virtual bool equals(Figure * f) const {
        if (f == nullptr) {
            return false;
        }

        Rectangle oth;
        try{
            oth = dynamic_cast<Rectangle &> (*f);
        } catch (const std::bad_cast& ex) {
            return false;
        }
        
        return (oth.a_ == a_ && oth.b_ == b_);
    }
};

class Triangle : public Figure {
    int a_, b_, c_;
public:
    Triangle(int a = 0, int b = 0, int c = 0) : a_(a), b_(b), c_(c) {}

    virtual ~Triangle() {}

    virtual bool equals(Figure * f) const {
        if (f == nullptr) {
            return false;
        }

        Triangle oth;
        try{
            oth = dynamic_cast<Triangle &> (*f);
        } catch (const std::bad_cast& ex) {
            return false;
        }

        return (oth.a_ == a_ && oth.b_ == b_ && oth.c_ == c_);
    }
};