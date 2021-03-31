#include <iostream>
#include <windows.h>
#include "Constants.h"
#include "OpenSuccess.h"
// Вариант 36

//#include <filesystem>
//namespace fs = std::filesystem;

void ClearAndRefill(std::fstream& filestr)
{
	// Открытие файла на запись и очистка файла
	filestr.open(file3, std::fstream::out | std::fstream::trunc);

	// Проверка открытия
	if (!OpenSuccess(filestr))
		return;

	// Заполнение файла тестовыми словами
	filestr << fileFill;

	// Закрытие файла
	filestr.close();
}


// find Возвращает npos, если не найден соответствующий элемент
// В данном случае мы ищем в строке исключаемых символов элемент c
// Возвращает true, если такой элемент есть и false, если нет
bool IsExclusion(char c, const std::string& exclude)
{
	size_t a = exclude.find(c);

	if (a != std::string::npos)
		return true;

	return false;
}

void EraseExclusions(std::string& word, std::string& result, const std::string& exclude)
{
	for (auto strIt = word.begin(); strIt != word.end(); strIt++)
	{
		if (!IsExclusion(*strIt, exclude))
			result += *strIt;
	}
	return;
}

void Prog5_3_2() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::fstream filestr;
	std::string exclude, word, result;

	// Очистка и заполнение файла
	ClearAndRefill(filestr);

	std::cout << "Введите символы, которые хотите исключить из файла" << std::endl;
	std::cin >> exclude;

	// Открытие файла на чтение и запись
	filestr.open(file3, std::fstream::in | std::fstream::out);

	// Проверка открытия
	if (!OpenSuccess(filestr))
		return;

	// Занесение данных в строку
	while (filestr >> word)
	{
		result += '\n';
		EraseExclusions(word, result, exclude);
	}

	
	//fs::resize_file(file3, 0);
	//filestr.seekp(0);

	filestr.close();
	// Очистка файла

	filestr.open(file3, std::fstream::out | std::fstream::trunc);
	
	if (!OpenSuccess(filestr))
		return;

	filestr.close();

	// Занесение конечных данных в файл
	filestr.open(file3);
	if (!OpenSuccess(filestr))
		return;

	filestr.write("Конечные данные: ", 17);
	filestr.write(result.c_str(), result.length());

	filestr.close();

	// Отображение конечных данных в консоль
	std::cout << "\nКонечные данные:"
		<< result << std::endl;
	return;
}
