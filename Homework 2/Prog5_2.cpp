#include <iostream>
#include <vector>

// Перегрузка для динамического массива
void PrimeChecker(int* &primes2, int& primesFound, int numberChecked)
{
	bool isPrime = true;

	// Проверяет делимость на все ранее найденые простые числа
	for (auto j = 0; j < primesFound; j++)
		if (numberChecked % primes2[j] == 0)
		{
			isPrime = false;
			break;
		}

	// Добавляет найденное простое число к вектору простых
	if (isPrime)
	{
		primes2[primesFound] = numberChecked;
		primesFound++;
	}
}

void PrimeChecker(std::vector<int> &primes, int &primesFound, int numberChecked)
{
	bool isPrime = true;

	// Проверяет делимость на все ранее найденые простые числа
	for (auto j = 0; j < primesFound; j++)
		if (numberChecked % primes[j] == 0)
		{
			isPrime = false;
			break;
		}

	// Добавляет найденное простое число к вектору простых
	if (isPrime)
	{
		primes[primesFound] = numberChecked;
		primesFound++;
	}
}

void Prog5_2() 
{
	int upperBound, method, primesFound = 1;
	std::vector<int> primes;

	// Ввод данных
	std::cout << "Алгоритм Решета Эратосфена для поиска простых чисел в диапазоне от 2 до заданного.\n" << std::endl;
	std::cout << "Введите число, до которого будет вестись поиск:" << std::endl;
	std::cin >> upperBound;

	// Проверка ввода
	if (upperBound <= 1)
	{
		std::cout << "Число должно быть больше единицы!" << std::endl;
		return;
	}

	std::cout << "Каким способом делать?"
		<< "\n1. Чеоез векторы"
		<< "\n2. Через динамические массивы" << std::endl;
	std::cin >> method;
	
	switch (method)
	{
	case 1:
		// Задание размера вектора и первого элемента
		primes.resize(ceil((double)upperBound / 2));
		primes[0] = 2;


		// Поиск простых
		for (auto number = 3; number <= upperBound; number++)
			PrimeChecker(primes, primesFound, number);

		// Вывод
		for (auto i = 0; i < primesFound; i++)
			std::cout << std::endl << i + 1 << ". " << primes[i];
		
		primes.clear();
		break;

	case 2:
	{
		// Задание размера массива и первого элемента
		int* primes2 = new int[ceil((double)upperBound / 2)];
		primes2[0] = 2;

		// Поиск простых
		for (auto number = 3; number <= upperBound; number++)
			PrimeChecker(primes2, primesFound, number);

		// Вывод
		for (auto i = 0; i < primesFound; i++)
			std::cout << std::endl << i + 1 << ". " << primes2[i];

		delete[] primes2;
		break;
	}
	default:
		std::cout << "Введён неправильный номер способа." << std::endl;
	}
	return;
}