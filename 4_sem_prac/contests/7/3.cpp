#include <iostream>

class S
{
    int num_{};
    bool read_{};
public:
    S()
    {
        read_ = bool{std::cin >> num_};
    }

    S(S&& other)
    {
        read_ = bool{std::cin >> num_};
        if (read_ && other.read_) {
            other.read_ = false; 
            num_ += other.num_;
        }
    }

    ~S()
    {
        if (read_) {
            std::cout << num_ << std::endl;
        }
    }

    operator bool()
    {
        return read_;
    }
};