#include <iostream>
#include <stack>
#include <string>

int Calculate(std::string str) {
    std::stack<int> stack; // Создаем стек для хранения операндов
    std::string token; // Объявляем переменную token для хранения текущего операнда

    for (unsigned long int i = 0; i < str.size(); )
    {
        token = "";
        while (i < str.size() && str[i] != ' ') // Формируем операнд или операцию
        {
            token += str[i];
            i++;
        }
        i++;
        if (token == "+") {
            int operand2 = stack.top(); stack.pop(); // Извлекаем верхний операнд из стека
            int operand1 = stack.top(); stack.pop(); // Извлекаем следующий операнд из стека
            stack.push(operand1 + operand2);
        }
        else if (token == "-") {
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            stack.push(operand1 - operand2);
        }
        else if (token == "*") {
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            stack.push(operand1 * operand2);
        }
        else if (token != "") {
            stack.push(std::stoi(token)); // Преобразуем строку в целое число и помещаем в стек
        }
    }
    return stack.top();
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    std::cout << Calculate(str) << std::endl;

    return 0;
}
