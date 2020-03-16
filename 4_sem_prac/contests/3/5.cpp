#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::vector<std::vector<std::pair<unsigned, bool>>> matrix;
    // input
    std::string s;
    std::getline(std::cin, s);
    while (s != "")
    {
        std::vector<std::pair<unsigned, bool>> v{};
        std::stringstream stream(s);
        int x;
        while (stream >> x)
        {
            v.push_back({x, x != 0 ? true : false});
        }
        std::getline(std::cin, s);
        matrix.push_back(v);
    }
    
    unsigned max = 0;
    std::pair <size_t, size_t> max_i = {0, 0};
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j].first > max)
            {
                max = matrix[i][j].first;
                max_i = {i, j};
            }
        }
    }

    unsigned x;
    while (std::cin >> x)
    {
        for (int i = -1; i < 2; ++i)
        {
            for (int j = -1; j < 2; ++j)
            {
                if (max_i.first + i >= 0 && max_i.first + i <= matrix[i].size()
                    && max_i.second + j >= 0 && max_i.second + j <= )
            }
        }
    }
}