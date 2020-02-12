// Шаг 1
void f(int *a, size_t n);

// Шаг 2
struct Range
{
    int *a;
    size_t n;
};

struct Square
{
    int a;
    int b; // a == b ("Инвариант")
};


void print(Range r) {
    for (size_t i = 0; i < r.n; ++i) {
        std::cout << r.a[i];
        std::cout.operator<<(r.a[i]);
    }
}

// Шаг 3
class String {
private:
    char *s;
    size_t len;

    // Выгоднее, тк выделяется на стеке
    char s[MAXLEN];
public:
    String(const char *s); // Конструктор
    ~String(); // Деструктор
    size_t Length() const {
        return len;
    }
};

// Конструктор
String::String(const char *s) {
    String::s = new char[strlen(s)] {};
    strcpy(this->s, s);
}

const String s;
s.Length();
