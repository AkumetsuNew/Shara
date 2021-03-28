#include <iostream>
#include <fstream>
#include "Constants.h"
//Проверка открытия файла
//Сделано

void Prog3_3()
{
    char c;
    std::fstream fs(file);
    std::string answer;

    if (!fs.is_open())
    {
        std::cout << "Файл не открылся" << std::endl;
        return;
    }

    while (fs.get(c))
        answer += c;


    fs.close();

    if (answer.empty()) std::cout << "Файл пуст." << std::endl;
    std::cout << answer << std::endl;
}