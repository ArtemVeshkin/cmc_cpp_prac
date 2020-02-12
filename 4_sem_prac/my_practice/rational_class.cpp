#include <iostream>
#include <string>

class Rational
{
int a, b;

    int gcd()
    {
        for (int i = a; i > 0; --i) {
            if (a % i == 0 && b % i == 0) {
                return i;
            }
        }
        return 1;
    }

    void cut()
    {
        int gcd = this->gcd();
        a /= gcd;
        b /= gcd;
    }
public:
    Rational()
    {
        this->a = 0;
        this->b = 1;
    }
    Rational(int a)
    {
        this->a = a;
        this->b = 1;
    }
    Rational(int a, int b)
    {
        this->a = a;
        this->b = b;
        cut();
    }

    Rational Add(Rational var)
    {
        a = a * var.b + b * var.a;
        b *= var.b;
        cut();

        return *this;
    }

    Rational Substract(Rational var)
    {
        a = a * var.b - b * var.a;
        b *= var.b;
        cut();

        return *this;
    }

    Rational Multiply(Rational var)
    {
        a *= var.a;
        b *= var.b;
        cut();

        return *this;
    }

    Rational Divide(Rational var)
    {
        if (var.a != 0) {
            a *= var.b;
            b *= var.a;
        } else {
            std::cerr << "Uncorrect input value (\"zero\")" << std::endl;
        }
        cut();

        return *this;
    }

    bool EqualTo(Rational var)
    {
        int gcd = 1;
        for (int i = gcd; i > 0; --i)
        {
            if (var.a % i == 0 && var.b & i == 0) {
                gcd = i;
                break;
            }
        }
        if (a == var.a / gcd && b == var.b / gcd) {
            return true;
        }
        return false;
    }

    int CompareTo(Rational var)
    {
        Rational tmp = *this;
        tmp.Substract(var);
        return tmp.a;
    }

    bool IsInteger()
    {
        if (b == 1 || a == 0) {
            return true;
        }
        return false;
    }

    std::string ToString()
    {
        std::string str = std::to_string(a);
        str += ":";
        str += std::to_string(b);
        return str;
    }
};