#include <cmath>
#include <algorithm>

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
        if (p1.col > p2.col)
        {
            std::swap(p1, p2);
        }

        T d_col  = p2.col - p1.col;
        T d_diag = p1.row - (d_col + p1.col % 2) / 2;

        if (p2.row <= (d_col + d_diag) && p2.row >= d_diag)
        {
            return d_col;
        }

        return std::min(std::abs(d_diag - p2.row), std::abs(d_diag - p2.row + d_col)) + d_col;
    }
}