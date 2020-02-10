#include <iostream>

#include <cstdint>

int main(int argc, const char *argv[])
{
    // Способы инициализировать нулём
    int64_t sum = 0;
    int64_t sum(0);
    int64_t sum{0};
    int64_t sum{};
    int64_t sum = int64_t();
    int64_t sum(); // Неправильно, тк ~ объявление функции

    // ---

    int64_t sum{};

    // Вариант 1
    while (1) {
        int a;

        std::cin >> a;
        if (std::cin.eof()) {
            break;
        }
        sum += a;
    }

    // Вариант 2
    int a;
    while (!(std::cin>>a).eof()) {
        sum += a;
    }

    // Вариант 3
    int a;
    while (std::cin >> a) {
        sum += a;
    }
    
    std::cout << sum;

    // ---
    // Сообщение для компилятора ("атрибут")
    [[maybe_unused]]
    bool z = bool(std::cin);

    // "Ломик" (c) Чернов А.В.
    bool z = true && std::cin;

    // Выглядит некрасиво
    bool z = static_cast<bool>(std::cin);
}