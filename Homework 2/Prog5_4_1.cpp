#include <iostream>
#include <cmath>
#include <vector>
// Вариант 10

// Функция кеширует значения факториалов для последующего использования
void CacheFactorial(std::vector<uint64_t>& facCache, const uint16_t& termAmount)
{
	for (auto i = 1; i <= termAmount; i++)
	{
		facCache[i] = (facCache[i - 1] * i);
	}
	return;
}


// Функция рассчитывает и кеширует значения синусов
double CalcSin(std::vector<double>& sinCache, uint16_t& termNum)
{
	double retVal = 0;
	sinCache[termNum] = sin(10 + (2 * termNum));

	for (uint16_t i = 1; i <= termNum; i++)
		retVal += sinCache[i];

	return retVal;
}

void SeriesSum(const uint16_t& termAmount)
{

	std::vector<double> sinCache;
	sinCache.resize(termAmount + 1);
	sinCache[0] = 0;

	std::vector<uint64_t> facCache;
	facCache.resize(termAmount + 1);
	facCache[0] = 1;

	long double result = 0;


	CacheFactorial(facCache, termAmount);


	for (uint16_t i = 1; i <= termAmount; i++)
	{
		result += facCache[termAmount - i + 1] / (pow(CalcSin(sinCache, i), i));
	}


	std::cout << "Результат:\n"
		<< result << std::endl;
	return;
}

void Prog5_4_1()
{
	uint16_t n;

	std::cout << "\nВычисление суммы ряда.\n" << std::endl;
	std::cout << "Введите число слагаемых" << std::endl;
	std::cin >> n;

	// Обработка ввода
	if (n < 1)
	{
		std::cout << "В ряду должно быть хотя бы одно слагаемое" << std::endl;
		return;
	}
	if (n > 244)
	{
		std::cout << "Невозможно вычислить больше 244 слагаемых (по крайней мере на моей машине)" << std::endl;
		return;
	}

	// Вызов функции, которая ищет сумму ряда
	SeriesSum(n);
	return;
}