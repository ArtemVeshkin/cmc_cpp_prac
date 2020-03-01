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

    class complex_stack
    {
        size_t size_, capacity_;
        complex *data_;

        void push(complex val)
        {
            if (capacity_ == size_)
            {
                capacity_ *= 2;
                complex *new_data = new complex[capacity_];
                for (int i = 0; i < size_; ++i)
                {
                    new_data[i] = data_[i];
                }
                delete[] data_;
            }
            ++size_;
            data_[size_ - 1] = val;
        }

        complex pop()
        {
            --size_;
            return data_[size_];
        }
    public:
        complex_stack(size_t size = 0) : size_(size), capacity_(size + 1) {
            data_ = new complex[capacity_];
        }

        complex_stack(complex_stack& base) {
            size_ = base.size();
            capacity_ = size_;
            data_ = new complex[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = base[i];
            }
        }

        ~complex_stack() { delete[] data_; }

        size_t size() const { return size_; }

        complex& operator[](size_t index) { return data_[index]; }

        complex_stack& operator<<(const complex& val)
        {
            complex_stack new_stack(*this);
            new_stack.push(val);
            return new_stack;
        }

        complex operator+() { return data_[size_ - 1]; }

        complex_stack operator~()
        {
            complex_stack new_stack(*this);
            new_stack.pop();
            return new_stack;
        }
    };
};

int main()
{
    numbers::complex_stack stack(5);
    for (int i = 0; i < 5; ++i)
    {
        stack[i] = {static_cast<double>(i)};
    }
    for (int i = 0; i < 5; ++i)
    {
        stack[i].print();
    }
}