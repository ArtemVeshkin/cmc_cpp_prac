#include <iostream>

namespace Sample
{
    template<typename T, size_t a, size_t b>
    class Matrix
    {
        T data_[a * b];
    public:
        T* operator[](size_t i)
        {
            return data_ + i * b;
        }

        const T* operator[](size_t i) const
        {
            return data_ + i * b;
        }
    };
}