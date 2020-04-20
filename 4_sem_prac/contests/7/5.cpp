#include <iostream>
#include <string>
#include <sstream>

#include <boost/date_time.hpp>
 
int main()
{
    boost::gregorian::date_duration result{};
    boost::gregorian::date prev;
 
    bool first_time{true};
    std::string str;
    while (std::getline(std::cin, str)) {
        for (size_t i = 0; i < str.size(); ++i)
        {
            if (str[i] == '-') {
                str[i] = ' ';
            }
        }

        int year, month, day;
        std::stringstream ss{str};
        ss >> year >> month >> day;

        boost::gregorian::date cur(year, month, day);
        if (first_time) {
            first_time = false;
            prev = cur;
        }

        boost::gregorian::date tmp = cur;
        
        if (cur < prev) {
            std::swap(cur, prev);
        }
        
        boost::gregorian::date_period p{prev, cur};
        result += p.length();

        prev = tmp;
    }

    std::cout << result << std::endl;
}