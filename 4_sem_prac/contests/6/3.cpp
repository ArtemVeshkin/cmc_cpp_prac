#include <cmath>

namespace Game
{
    template <typename T>
    class Coord
    {
    public:
        typedef T value_type;
        T row, col;

        Coord(void) {}
        Coord(T row) : row(row) {}
        Coord(T row, T col) : row(row), col(col) {}
    };

    template <typename T>
    T dist(Coord<T> sz, Coord<T> p1, Coord<T> p2)
    {
        T dx = p1.row - p2.row;
        T dy = p1.col - p2.col;
        T du = dx - 0.5 * dy;
        T dv = 0.866 * dy;
        return std::sqrt(du * du + dv * dv);
    }
}