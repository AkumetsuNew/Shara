#include <iostream>
#include "Constants.h"
#include <Windows.h>
const int firstRusLet = -65;
const int lastRusLet = 0;
const int winLen1251 = 256;
//Подключить windows.h для русских символов
//Сделано

void Prog3_5()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string letters;
    int charCount[winLen1251] = { 0 };

    std::cout << "Введите буквы" << std::endl;
    std::cin >> letters;

    for (auto i = 0; i < letters.length(); i++) 
    {
        std::cout << letters[i] << "  " << (int)letters[i];

        if (!isalpha(letters[i]) && letters[i] < firstRusLet && letters[i] > lastRusLet)
        {
            std::cout << "Введён неверный символ" << std::endl;
            return;
        }
 
        charCount[(int)letters[i] + 128]++;
    }

    letters.clear();

    for (auto i = -128; i < 128; i++)
        for (auto j = 0; j < charCount[i + 128]; j++)
            letters += (char)(i);

    std::cout << "Отсортированная в алфавитном порядке строка:" << std::endl;
    std::cout << letters;
}
