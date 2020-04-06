#include <string>
#include <sstream>
#include <cmath>

#define _USE_MATH_DEFINES

class Rectangle : Figure
{
    double a_, b_;

public:
    double get_square() const override
    {
        return a_ * b_;
    }

    static Rectangle* make(std::string params)
    {
        std::stringstream stream(params);
        double a, b;
        stream >> a >> b;

        Rectangle* new_figure = new Rectangle;
        new_figure->a_ = a;
        new_figure->b_ = b;

        return new_figure;
    }
};

class Square : Figure
{
    double a_;

public:
    double get_square() const override
    {
        return a_ * a_;
    }

    static Square* make(std::string params)
    {
        std::stringstream stream(params);
        double a;
        stream >> a;

        Square* new_figure = new Square;
        new_figure->a_ = a;

        return new_figure;
    }
};

class Circle : Figure
{
    double r_;

public:
    double get_square() const override
    {
        return M_PI * r_ * r_;
    }

    static Circle* make(std::string params)
    {
        std::stringstream stream(params);
        double r;
        stream >> r;

        Circle* new_figure = new Circle;
        new_figure->r_ = r;

        return new_figure;
    }
};