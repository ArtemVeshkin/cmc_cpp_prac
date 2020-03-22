#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>

size_t correction_point(int x, int y, size_t correction)
{
    if (x == 0 && y == 0)
    {
        return correction;
    } else if (x == 0 || y == 0) {
        return correction / 2;
    }
    return 0;
}

int main()
{
    std::vector<std::vector<size_t>> matrix;
    // input
    std::string s;
    std::getline(std::cin, s);
    while (s != "")
    {
        std::vector<size_t> v{};
        std::stringstream stream(s);
        int x;
        while (stream >> x)
        {
            v.push_back(x);
        }
        std::getline(std::cin, s);
        matrix.push_back(v);
    }

    // Max
    std::map<size_t, std::set<std::pair<int, int>>, std::greater<size_t>> max;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            max[matrix[i][j]].insert({i, j});
        }
    }

    // Corrections
    size_t x;
    while (std::cin >> x)
    {
        std::pair cur_max = *max.begin()->second.begin();
        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                int cur_x = cur_max.first + i;
                int cur_y = cur_max.second + j;
                if (cur_x >= 0 && cur_x < static_cast<int>(matrix.size())
                    && cur_y >= 0 && cur_y < static_cast<int>(matrix[cur_x].size()))
                {
                    size_t correction = correction_point(i, j, x);
                    size_t prev_val = matrix[cur_x][cur_y];
                    if (correction >= prev_val)
                    {
                        matrix[cur_x][cur_y] = 0;
                    } else {
                        matrix[cur_x][cur_y] -= correction;
                    }
                    max[prev_val].erase({cur_x, cur_y});
                    max[matrix[cur_x][cur_y]].insert({cur_x, cur_y});
                    if (max[prev_val].empty())
                    {
                        max.erase(prev_val);
                    }
                }
            }
        }
    }

    for (const auto row : matrix)
    {
        for (const auto elem : row)
        {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}