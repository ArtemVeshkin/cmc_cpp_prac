
namespace numbers
{
    class complex_stack
    {
        size_t size_, pos_;
        complex* ptr_;

        void push(complex val)
        {
            ++pos_;
            if (pos_ < size_)
            {
                size_ <<= 2;
                complex* new_stack = new complex[size_];
                for (int i = 0; i + 1 < pos_; ++i)
                {
                    new_stack[i] = ptr_[i];
                }
                delete[] ptr_;
                ptr_ = new_stack;
            }
            ptr_[pos_ - 1] = val;
        }

    public:
        complex_stack() : size_(0), pos_(0), ptr_(NULL) {}

        complex_stack(size_t size) : size_(size), pos_(size)
        {
            ptr_ = new complex[size];
        }

        ~complex_stack() { delete[] ptr_; }

        size_t size() { return size_; }

        complex& operator[](int i) { return ptr_[i]; }

        complex_stack operator<<(complex val)
        {
            complex_stack new_stack = *this;
            new_stack.push(val);
            return new_stack;
        }

        complex operator+() { return ptr_[pos_ - 1]; }

        complex_stack operator~()
        {
            complex_stack new_stack = *this;
            delete &new_stack[new_stack.pos_ - 1];
            return new_stack;
        }
    };
};