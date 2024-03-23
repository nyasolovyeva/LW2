#include <iostream>
#include <stack>
#include <string>

int Calculate(std::string str) {
    std::stack<int> stack; // ������� ���� ��� �������� ���������
    std::string token; // ��������� ���������� token ��� �������� �������� ��������

    for (unsigned long int i = 0; i < str.size(); )
    {
        token = "";
        while (i < str.size() && str[i] != ' ') // ��������� ������� ��� ��������
        {
            token += str[i];
            i++;
        }
        i++;
        if (token == "+") {
            int operand2 = stack.top(); stack.pop(); // ��������� ������� ������� �� �����
            int operand1 = stack.top(); stack.pop(); // ��������� ��������� ������� �� �����
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
            stack.push(std::stoi(token)); // ����������� ������ � ����� ����� � �������� � ����
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
