#include <iostream>
#include <Windows.h>
#include <string>
#include <set>
#include "OpenSuccess.h"

const char firstRusLet = -65;
const char lastRusCapitalLet = -33;
const char lastRusLet = -1;
const std::string numbers = "0123456789";
//const uint16_t winLen1251 = 256;

// Возвращает true, если введено слово стоп/синоним
bool InputIsStop(const std::string& input)
{
	std::set<std::string> stopStrings
	{
		"Stop", "stop", "s", "S",
		"Стоп", "стоп", "с", "С"
	};
	if (stopStrings.count(input))
		return true;
	return false;
}

bool IsNotCapital(const char& c)
{
	if (c < firstRusLet || c > lastRusCapitalLet)
		return true;
	else
		return false;
}

bool IsNotAlphaRussian(const char& c)
{
	if (c == '-' || c == 'ё' || c == 'Ё') return false;
	if (c < firstRusLet || c > lastRusLet)
		return true;
	else
		return false;
}

// Возвращает true, если ввод не подходит формату
bool InputIsInvalid(const std::string& input)
{
	const size_t idWidth = (6 - 1);
	// Проверка пробелов, должен быть ровно один
	if (input.find_first_of(' ') != input.find_last_of(' ') // Проверка 1: больше одного пробелпа
		||													// Или
		input.find_first_of(' ') == std::string::npos)		// Проверка 2: нет пробелов
	{
		std::cout << "В строке должен быть ровно один пробел." << std::endl;
		return true;
	}

	// Проерка первой буквы, должна быть русской заглавной
	if (IsNotCapital(*input.begin()))
	{
		std::cout << "Первая буква должна быть русской заглавной." << std::endl;
		return true;
	}

	auto spacePosIt = input.begin() + input.find_first_of(' ');

	// Проверка первого "слова"(до пробела), должно состоять из русских букв
	for (auto strIt = input.begin() + 1; strIt != spacePosIt; ++strIt)
	{
		
		if (IsNotAlphaRussian(*strIt))
		{
			std::cout << "Фамилия должна состоять из русских букв." << std::endl;
			return true;
		}
	}

	// Проверяет количество цифр, должно быть шесть
	if (input.find_last_of(numbers) - input.find_first_of(numbers) != idWidth)
	{
		std::cout << "Шифр должен состоять ровно из шести цифр." << std::endl;
		return true;
	}

	auto firstNumPosIt = input.begin() + input.find_first_of(numbers);
	auto lastNumPosIt = input.begin() + input.find_last_of(numbers);
 	
	// Проверяет, что последняя цифра — последний элемент строки
	if (lastNumPosIt + 1 != input.end())
	{
		std::cout << "Ввод должен заканчиваться шифром" << std::endl;
		return true;
	}

	// Проверяет, что между первой и последней цифрой только цифры
	for (auto strIt = firstNumPosIt; strIt != input.end(); strIt++)
	{
		if (!isdigit(*strIt))
		{
			std::cout << "Шифр должен состоять из цифр" << std::endl;
			return true;
		}
	}
	return false;
}

// Ввод данных
bool Input(std::string& inputWhole)
{
	std::string inputStr = inputWhole;
	if (inputStr.empty())
		std::cout << "Сейчас вы будете вводить данные.\n"
			<< "Формат данных:\n"
			<< "<Фамилия с заглавной буквы кириллицей><Пробел><Индекс из шести цифр>\n"
			<< "Чтобы остановиться, напишите стоп или с\n"
			<< std::endl;

	while (true)
	{
		std::cout << "Введите фамилию и шифр студента через пробел:\n" << std::endl;

		// Для правильной работы getline, вызывается в первом цикле
		if (inputStr.empty())
			std::cin.ignore();

		std::getline(std::cin, inputStr);

		//std::cout << inputStr << std::endl;
		//std::cout << "\n" << inputStr << "\n";

		//for (auto it = inputStr.begin(); it != inputStr.end(); it++)
		//	std::cout << (int)*it << " " << *it << std::endl;


		// Проверяет, хочет ли пользователь остановиться
		if (InputIsStop(inputStr)) break;
		// Проверяет правильность ввода
		if (InputIsInvalid(inputStr)) return false;

		
		

		inputWhole += inputStr + '\n';
	}

	return true;
}

void Prog5_5()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::fstream fs;
	std::string inputWhole;

	std::cout << "\nПрограмма для ввода и просмотра данных студентов\n" << std::endl;

	while (!Input(inputWhole))
		std::cout << "Неправильный ввод, попробуйте снова\n\n" << std::endl;

	std::cout << "\n" << inputWhole;
}
