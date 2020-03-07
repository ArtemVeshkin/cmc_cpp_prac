#include "include.h"

namespace numbers
{
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
                for (size_t i = 0; i < size_; ++i)
                {
                    new_data[i] = data_[i];
                }
                delete[] data_;
                data_ = new_data;
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
        complex_stack() : size_(0), capacity_(1), data_(nullptr) {
            data_ = new complex[capacity_];
        }

        complex_stack(size_t size) : size_(size), capacity_(size + 1), data_(nullptr) {
            data_ = new complex[capacity_];
        }

        complex_stack(const complex_stack& base) : size_(0), capacity_(1), data_(nullptr)
        {
            size_ = base.size();
            capacity_ = size_;
            data_ = new complex[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = base[i];
            }
        }

        ~complex_stack() { delete[] data_; }

        complex_stack operator=(const complex_stack& base)
        {
            size_ = base.size();
            capacity_ = size_;
            data_ = new complex[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                data_[i] = base[i];
            }
        }

        size_t size() const { return size_; }

        complex& operator[](size_t index) const { return data_[index]; }

        complex_stack operator<<(const complex val) const
        {
            complex_stack new_stack = *this;
            new_stack.push(val);
            return new_stack;
        }

        complex operator+() const { return data_[size_ - 1]; }

        complex_stack operator~() const
        {
            complex_stack new_stack = *this;
            new_stack.pop();
            return new_stack;
        }
    };
};

int main()
{
    // numbers::complex_stack stack;
}