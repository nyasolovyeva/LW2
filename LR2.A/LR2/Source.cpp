#include <iostream>
#include <set>

int main() 
{
    int N;
    std::cin >> N;

    int number;
    std::set<int> difNum; // —оздаем множество дл€ хранени€ различных чисел
    for (int i = 0; i < N; i++)
    {
        std::cin >> number;
        difNum.insert(number);
    }

    std::cout << difNum.size() << std::endl;

    return 0;
}