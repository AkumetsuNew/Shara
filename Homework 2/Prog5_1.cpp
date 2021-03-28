#include <iostream>

void FindGCD(int &num1, int &num2) // Записывает в большее число остаток от деления на меньшее
{
	if (num1 > num2)
		num1 %= num2;
	else
		num2 %= num1;
	return;
}

void Prog5_1()
{
	int num1, num2;

	std::cout << "Алгоритм Евклида для нахождения наибольшего общего делителя двух целых чисел.\n" << std::endl;
	std::cout << "Введите первое число:" << std::endl;
	std::cin >> num1;
	std::cout << "Введите второе число:" << std::endl;
	std::cin >> num2;

	// Проверка ввода
	if (num1 <= 0 || num2 <= 0)
	{
		std::cout << "Числа должны быть больше нуля." << std::endl;
		return;
	}


	while (num1 != 0 && num2 != 0)
		FindGCD(num1, num2); // В конце цикла одна переменная будет равна НОД, другая — нулю


	std::cout << "Наибольший общий делитель:" << std::endl;
	std::cout << num1 + num2;
	// Сумма НОД + 0 = НОД
	return;
}