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