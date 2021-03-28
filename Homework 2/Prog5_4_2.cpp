#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
// Вариант 36

uint16_t Min(uint16_t a, uint16_t b)
{
	if (a < b)
		return a;
	return b;
}

void Prog5_4_2()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string inputStr;
	std::vector<char> inputVec;
	uint16_t n, minWord = UINT16_MAX, curWord = 0;

	std::cout << "\nПрограмма для нахождения самого короткого слова\n" << std::endl;


	std::cout << "Введите число считываемых символов:" << std::endl;
	std::cin >> n;
	
	std::cout << "Введите строку со словами, разделяемыми пробелом:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, inputStr);
	
	// Отображает усечённую строку
	std::cout << "\nБудет обработана строка:\n"
		<< inputStr.substr(0, n) << std::endl;

	// Меняет размер вектора и добавляет к нему строку (или её часть)
	if (size(inputStr) <= n)
	{
		inputVec.resize(inputStr.size());
		inputVec.assign(inputStr.begin(), inputStr.end());
	}
	else
	{
		inputVec.resize(n);
		inputVec.assign(inputStr.begin(), inputStr.begin() + n);
	}

	// Итерирует длину текущего слова, если итератор вектора не на пробеле
	// Если итератор на пробеле или следующая позиция итератора -- конец вектора
	// Записывает в минимальное слово минимальное из текущего слова и предыдущего минимального
	for (auto vecIt = inputVec.begin(); vecIt != inputVec.end(); ++vecIt)
	{
		if (*vecIt != ' ')
			curWord++;
		if (*vecIt == ' ' || vecIt + 1 == inputVec.end())
		{
			minWord = Min(minWord, curWord);
			curWord = 0;
		}
	}
	
	std::cout << "Длина самого короткого слова:\n"
		<< minWord << std::endl;
	return;
}