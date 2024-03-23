#include <iostream>  
#include <map>  
#include <string>  

int main() {
    // 49. ������ �� �������
    typedef std::multimap<int, std::string> MMap;
    MMap znach; // ��������� ��� �������� ��� int/string

    int grade;
    std::string surname;

    while (std::cin >> grade >> surname) {
        znach.insert(std::make_pair(grade, surname));
    }
    std::cout << std::endl;
    // ������� ���������� ���������� (������� ���� ���������)
    MMap::iterator pos;
    for (pos = znach.begin(); pos != znach.end(); ++pos) {
        std::cout << pos->first << " " << pos->second << std::endl;
    }
    return 0;
}