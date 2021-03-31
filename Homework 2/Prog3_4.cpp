#include <iostream>
#include <fstream>
#include "Constants.h"
#include "OpenSuccess.h"
//Проверка открытия файла
//Сделано

void Prog3_4()
{
    char c;
    std::string answer;
    std::fstream fs(file2);

    if (!OpenSuccess(fs))
        return;

    while (fs.get(c))
        if (isdigit(c)) answer += c;

    fs.close();

    std::cout << "Цифры, содержащиеся в файле:" << std::endl;

    if (answer.empty())
    {
        std::cout << "В файле нет цифр." << std::endl;
        return;
    }
    
    std::cout << answer << std::endl;
    return;
}
