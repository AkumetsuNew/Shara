#include <iostream>
#include <vector>

void Series()
{
	double x, eps;
	uint32_t minIndex = 14;
	std::vector < double > seriesValue;

	std::cout << "\n\nПрограмма для нахождения предела ряда." << std::endl;

	std::cout << "Введите число x." << std::endl;
	std::cin >> x;
	std::cout << "Введите число эпсилон" << std::endl;
	std::cin >> eps;

	seriesValue.push_back(1);
	seriesValue.push_back(x);
	seriesValue.push_back(pow(x,3));
	for (uint32_t i = 3; i <= 1'000'000; i++)
	{
		seriesValue.push_back
		(
			(12 - x * seriesValue.at(i - 1))
			/
			(pow(seriesValue.at(i - 2), 2) + sqrt(abs(seriesValue.at(i - 3))))
		);

		if (i > minIndex && abs(seriesValue.at(i) - seriesValue.at(i - 1)) < eps)
		{
			std::cout << "Найден элемент " << seriesValue.at(i) << " под номером " << i << std::endl;
			break;
		}
		if (i == 1'000'000)
		{
			std::cout << "Искомый элемент не найден за миллион итераций" << std::endl;
		}
	}
	return;
}
