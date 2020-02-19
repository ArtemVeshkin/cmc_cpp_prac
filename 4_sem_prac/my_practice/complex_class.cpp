#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>

namespace numbers
{
    class complex
    {
        double re, im;

        void test_stream(std::stringstream &stream, char c)
        {
            if (stream.peek() != c)
                {
                    std::stringstream ex;
                    ex << "expected /, but has: " << (char) stream.peek();
                    throw std::runtime_error(ex.str());
                }
        }
    public:
        complex(const double re = 0., const double im = 1.)
        {
            this->re = re;
            this->im = im;
        }
        explicit complex(const char *str)
        {
            std::stringstream stream{std::string(str)}; 
            try
            {
                test_stream(stream, '(');
                stream.ignore(1);
                stream >> re;
                test_stream(stream, ',');
                stream.ignore(1);
                stream >> im;
            }
            catch(const std::exception& ex)
            {
                std::cerr << ex.what() << std::endl;
            }
            
        }
        double get_re() const
        {
            return re;
        }
        double get_im() const
        {
            return im;
        }
        double abs() const
        {
            return sqrt(re * re + im * im);
        }
        double abs2() const
        {
            return re * re + im * im;
        }
        void to_string(char *buf, size_t size)
        {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }
        complex operator+(complex val)
        {
            return complex(re + val.re, im + val.im);
        }
        complex operator-(complex val)
        {
            return complex(re - val.re, im - val.im);
        }
        complex operator*(complex val)
        {
            return complex(re * val.re - im * val.im,
                           re * val.im + im * val.re);
        }
        complex operator/(complex val)
        {
            double k = val.re * val.re + val.im * val.im;
            return ((re * val.re + im * val.im) / k,
                    (-re * val.im + im * val.re) / k);
        }
        complex operator~()
        {
            return complex(re, -im);
        }
        complex operator-()
        {
            return complex(-re, -im);
        }
        void print()
        {
            printf("(%.10g,%.10g)\n", re, im);
        }
    };
};

int main()
{
    numbers::complex num1("1, 2"), num2(3, 1);
    (num1 + num2).print();     
}