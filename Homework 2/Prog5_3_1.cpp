// Вариант 10
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include "OpenSuccess.h"

//const std::string consonants = "бвгджзйклмнпрстфхцчшщъь";
const std::string vowels = "аеёиоуыэюя";
const std::string irregulars = "ъь";


// find Возвращает npos, если не найден соответствующий элемент
// В данном случае мы ищем в строке гласных элемент c
// Возвращает true, если такой элемент есть и false, если нет
bool IsVowel(char c)
{
    size_t a = vowels.find(c);

    if (a != std::string::npos)
        return true;

    return false;
}


// find Возвращает npos, если не найден соответствующий элемент
// В данном случае мы ищем в строке неправильных букв элемент c
// Возвращает true, если такой элемент есть и false, если нет
bool IsIrregularLetter(char c)
{
    size_t a = irregulars.find(c);

    if (a != std::string::npos)
        return true;

    return false;
}

void AddToResult(std::string& word, std::string& result)
{
    size_t foundPos = word.find_first_of(vowels);
    size_t foundLast = 0;
    size_t foundNew;
    bool LastWasClosest = false;

    while (foundPos != std::string::npos)
    {

        // Если после найденной гласной следующая буква - гласная
        // Добавляет одну букву, если прошлая была гласной
        // Или две, если прошлая -- не гласная
        if (IsVowel(word[foundPos + 1]))
        {
            if (LastWasClosest)
                result += word.substr(foundLast, 1) + '-';
            else
                result += word.substr(foundLast, foundPos - foundLast + 1) + '-';

            foundLast = foundPos;
            LastWasClosest = true;
        }

        // Если дальше нет гласных, добавляет всё, что осталось
        else if (word.find_first_of(vowels, foundPos + 1) == std::string::npos)
        {
            //substr с одним аргументом выводит до конца
            if (LastWasClosest)
                result += word.substr(foundPos);
            else
                result += word.substr(foundLast);
            break;
        }

        // Если следующая гласная появляется через одну букву
        // То добавляется текущая и следующая буквы, если прошлая была гласной
        // Или предыдущая, текущая и следующая, если прошлая была согласной
        // Если перед следующей гласной стоит ь или ъ, то он тоже добавляется
        else if (IsVowel(word[foundPos + 2]))
        {
            if (LastWasClosest)
                foundLast++;
            if (IsIrregularLetter(word[foundPos + 1]))
                foundPos++;
            result += word.substr(foundLast, foundPos - foundLast + 1) + '-';
            foundLast = foundPos + 1;
            LastWasClosest = false;
        }

        // Если следующая гласная появляется через несколько букв
        // То добавляется текущая и следующие буквы (оставляя одну перед следующей гласной), если прошлая была гласной
        // Или предыдущая, текущая и следующие, если прошлая была согласной
        // Если перед следующей гласной стоит ь или ъ, то он тоже добавляется
        else
        {
            foundNew = foundPos + 1;
            
            if (IsIrregularLetter(word[foundNew + 1]))
                foundNew++;
            if (LastWasClosest)
                foundLast++;
            // Если ближайшая гласная больше, чем через две буквы,
            // конец подстроки будет на две буквы раньше следующей гласной
            result += word.substr(foundLast, foundNew - foundLast + 1) + '-';
            foundLast = foundNew + 1;
            LastWasClosest = false;
        }

        // Находится следующая согласная
        foundPos = word.find_first_of(vowels, foundPos + 1);
    }
    result += ' ';
}

void DivideBySyllables(std::fstream& fs)
{
    std::string result, word;

    // Вызывает AddToResult для каждого слова (слово определяется пробелом)
    while (fs >> word)
        AddToResult(word, result);

    std::cout << result << std::endl;
}

// Проверка открытия
//bool OpenSuccess(std::fstream& fs) 
//{
//    if (!fs.is_open())
//    {
//        std::cout << "Не удалось открыть файл." << std::endl;
//        return false;
//    }
//    return true;
//}

void Prog5_3_1()
{
    // Для русских символов 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string FILENAME, inputarr;
    std::fstream fs;

    std::cout << "Введите название файла:" << std::endl;
    std::cin >> FILENAME;
    FILENAME += ".txt";

    // Открытие файла на запись
    fs.open(FILENAME, std::fstream::out);

    // Проверка открытия
    if (!OpenSuccess(fs)) return;

    // Заполнение и закрытие файла
    std::cout << "Введите текст:\n";
    std::cin.ignore();
    std::getline(std::cin, inputarr);
    std::transform(inputarr.begin(), inputarr.end(), inputarr.begin(), ::std::tolower);
    fs << inputarr;
    
    // Закрытие файла
    fs.close();
    
    // Открытие файла на чтение
    fs.open(FILENAME, std::fstream::in);

    // Проверка открытия
    if (!OpenSuccess(fs))
        return;

    // Поиск и вывод слогов
    DivideBySyllables(fs);
    
    // Закрытие файла
    fs.close();

    
    // Удаление файла
    remove(FILENAME.c_str());
    return;
}
