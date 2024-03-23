#include <iostream>
#include <stack>
#include <string>

bool order(std::string s) 
{
    std::stack<char> stack;
    for (char c : s) //Перебираем каждый символ в строке
    {
        if (c == '(' || c == '[' || c == '{') 
        {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') 
        {
            if (stack.empty()) 
            {
                return false; // Возвращаем false, если есть закрывающая скобка без соответствующей открывающей
            }
            char open = stack.top();// Извлекаем открывающуюся скобку на вершине стека
            stack.pop();
            if ((c == ')' && open != '(') || (c == ']' && open != '[') || (c == '}' && open != '{')) 
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string brackets;
    std::cin >> brackets;

    if (order(brackets)) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}