#include <iostream>  
#include <map>  
#include <string>  

int main() {
    // 49. Списки по классам
    typedef std::multimap<int, std::string> MMap;
    MMap znach; // Контейнер для хранения пар int/string

    int grade;
    std::string surname;

    while (std::cin >> grade >> surname) {
        znach.insert(std::make_pair(grade, surname));
    }
    std::cout << std::endl;
    // Выводим содержимое контейнера (перебор всех элементов)
    MMap::iterator pos;
    for (pos = znach.begin(); pos != znach.end(); ++pos) {
        std::cout << pos->first << " " << pos->second << std::endl;
    }
    return 0;
}