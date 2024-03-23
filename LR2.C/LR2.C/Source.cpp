#include <iostream>
#include <deque>
#include <cmath>

int main() {
    //50. Игра в пьяницу
    std::deque<int> first, second;

    for (int i = 0; i < 5; ++i) {
        int card1;
        std::cin >> card1;
        first.push_front(card1); //Присоединяем копию card1 в начало дека
    }

    for (int i = 0; i < 5; ++i) {
        int card2;
        std::cin >> card2;
        second.push_front(card2); //Присоединяем копию card2 в начало дека
    }

    int k = 0;
    while (!first.empty() && !second.empty() && k < pow(10, 6)) {
        int card1 = first.back(); //присваиваем последний элемент в first
        int card2 = second.back(); //присваиваем последний элемент в second
        //Удаляем последние элементы
        first.pop_back();
        second.pop_back();

        if (card1 == 0 && card2 == 9) {
            first.push_front(card1);
            first.push_front(card2);
        }
        else if (card1 == 9 && card2 == 0) {
            second.push_front(card1);
            second.push_front(card2);
        }
        else if (card1 > card2) {
            first.push_front(card1);
            first.push_front(card2);
        }
        else {
            second.push_front(card1);
            second.push_front(card2);
        }
        k += 1;
    }
    std::cout << std::endl;

    if (first.empty()) {
        std::cout << "second " << k << std::endl;
    }
    else if (second.empty()) {
        std::cout << "first " << k << std::endl;
    }
    else {
        std::cout << "botva" << std::endl;
    }

    return 0;
}