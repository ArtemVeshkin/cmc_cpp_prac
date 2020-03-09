#include <string>
#include <vector>
#include <map>
#include <stack>
#include <functional>

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        std::stack<complex> stack;
        std::map<std::string, std::function<void()>> operations = 
        {
            {"z", [&stack, &z](){
                stack.emplace(z);
            }},
            {"+", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.top() += c;
            }},
            {"-", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.top() -= c;
            }},
            {"*", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.top() *= c;
            }},
            {"/", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.top() /= c;
            }},
            {"!", [&stack](){
                stack.emplace(stack.top());
            }},
            {";", [&stack](){
                stack.pop();
            }},
            {"~", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.emplace(~c);
            }},
            {"#", [&stack](){
                complex c = stack.top(); stack.pop();
                stack.emplace(-c);
            }}
        };

        for (const auto &op : args)
        {
            if (op[0] == '(')
            {
                stack.push(complex(op));
            } else {
                operations[op]();
            }
        }
        return stack.top();
    }
}