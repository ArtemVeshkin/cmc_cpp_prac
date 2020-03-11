#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<int> v1{1, 2, 3};
    std::vector<std::string> v2{"a", "b", "c"};

    std::cout << v2.size() << " " << v2.capacity() << std::endl;

    std::vector<double> v3(10, 0.5);
    v3.erase(v3.begin(), v3.end() + 3);

    v2.pop_back();
}