#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>

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
    size_t max = 0;
    std::pair<int, int> max_i = {0, 0};
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
                max_i = {i, j};
            }
        }
    }
    // Corrections
    size_t x;
    while (std::cin >> x)
    {
        for (int i = -1; i < 2; ++i)
       {
            for (int j = -1; j < 2; ++j)
            {
                if (max_i.first + i >= 0 
                    && max_i.first + i < static_cast<int>(matrix.size())
                    && max_i.second + j >= 0 
                    && max_i.second + j < static_cast<int>(matrix[max_i.first + i].size()))
                {
                    size_t correction = correction_point(i, j, x);
                    if (correction <= matrix[i][j])
                    {
                        matrix[max_i.first + i][max_i.second + j] = 0;
                    } else {
                        matrix[max_i.first + i][max_i.second + j] -= correction;
                    }
                }
            }

            for (auto row : matrix)
            {
                for (auto elem : row)
                {
                    std::cout << elem << ' ';
                }
                std::cout << std::endl;
            }
        }

        
    }

    for (auto row : matrix)
    {
        for (auto elem : row)
        {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }

    system("pause");
}