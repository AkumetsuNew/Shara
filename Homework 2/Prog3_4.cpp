#include <iostream>
#include <fstream>
#include "Constants.h"
//Проверка открытия файла
//Сделано

std::string Prog3_4()
{
    char c;
    std::string answer;
    std::fstream fs(file2);

    if (!fs.is_open())
        return "Файл не открылся";

    while (fs.get(c))
        if (isdigit(c)) answer += c;

    fs.close();

    if (answer.empty()) return "Нет цифр.";
    return answer;
}