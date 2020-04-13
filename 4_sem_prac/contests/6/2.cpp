#include <algorithm>

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
    if (p1.row < p2.row)
    {
        std::swap(p1.row , p2.row);
    }
    if (p1.col < p2.col)
    {
        std::swap(p1.col, p2.col);
    }

    T dr = std::min(p1.row - p2.row, p2.row + sz.row  - p1.row);
    T dc = std::min(p1.col - p2.col, p2.col + sz.col - p1.col);

    return std::max(dr, dc);
}