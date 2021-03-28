#include <iostream>
#include <fstream>
#include <string>
//Проверка открытия файла
//Сделано

void Prog4_1() 
{
    // Создание файла
    std::string FILENAME, inputarr, input;
    std::fstream fs;
    std::cout << "Введите название файла:" << std::endl;
    std::cin >> FILENAME;
    FILENAME += ".txt";

    // Заполнение файла
    fs.open(FILENAME, std::fstream::out);

    if (!fs.is_open())
    {
        std::cout << "Файл не открылся" << std::endl;
        return;
    }

    std::cout << "\nВведите 10 чисел (знак дроби вводить через запятую):" << std::endl;
    for (auto i = 0; i < 10; i++)
    {
        std::cout << "Число " << i + 1 << ":" << std::endl;
        std::cin >> input;
        inputarr += input + ' ';
    }
    fs << inputarr;
    fs.close();

    //Чтение файла
    double answer = 0;
    char c;
    std::string numbers;
    fs.open(FILENAME, std::fstream::in);

    if (!fs.is_open())
    {
        std::cout << "Файл не открылся" << std::endl;
        return;
    }

    while (fs.get(c)) 
    {
        if (isdigit(c) || c == '.' || c == '-' || c == ',')
        {
            numbers += c;
        }
        else
        {
            answer += stod(numbers);
            numbers.clear();
        }
    }
    fs.close();

    //Вывод ответа
    std::cout << "Сумма чисел в файле:" << std::endl;
    std::cout << answer << std::endl;
}