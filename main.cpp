#include "include.h"

namespace numbers
{
    class complex_stack
    {
        size_t size_, capacity_;
        complex *data_;

        void push(const complex& val)
        {
            if (capacity_ == size_)
            {
                capacity_ *= 2;
                complex *new_data = static_cast<complex*> (
                    ::operator new (capacity_ * sizeof(*new_data)));
                for (size_t i = 0; i < size_; ++i)
                {
                    new_data[i] = data_[i];
                }
                delete[] data_;
                data_ = new_data;
            }
            new(data_ + size_++) complex(val);
        }

        void pop() { (data_ + --size_)->~complex(); }
    public:
        complex_stack(size_t size = 0) : size_(size), capacity_(size + 1), data_(nullptr) {
            data_ = static_cast<complex*> (::operator new (capacity_ * sizeof(*data_)));
            for (size_t i = 0; i < capacity_; ++i)
            {
                new(data_ + i) complex(); 
            }
        }

        complex_stack(const complex_stack& base) : size_(base.size_),
            capacity_(base.capacity_), data_(nullptr)
        {
            data_ = static_cast<complex*> (::operator new (capacity_ * sizeof(*data_)));
            for (size_t i = 0; i < size_; ++i)
            {
                new(data_ + i) complex(base[i]);
            }
        }

        ~complex_stack() { delete[] data_; }

        void operator=(const complex_stack& base)
        {
            if (&base == this) { return; }
            
            if (capacity_ < base.capacity_)
            {
                delete[] data_;
                size_ = base.size_;
                capacity_ = base.capacity_;
                data_ = static_cast<complex*> (::operator new (capacity_ * sizeof(*data_)));
                for (size_t i = 0; i < capacity_; ++i)
                {
                    new(data_ + i) complex(base[i]);
                }
            } else {
                size_ = base.size_;
                for (size_t i = 0; i < capacity_; ++i)
                {
                    data_[i] = base.data_[i];
                }
            }
        }

        size_t size() const { return size_; }

        complex& operator[](size_t index) const { return data_[index]; }

        complex_stack operator<<(const complex& val) const
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