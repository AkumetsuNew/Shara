#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void PrintIntegersVec(const std::vector<int>& vec)
{
	uint16_t it = 0;
	for (auto number : vec)
	{
		it++;
		std::cout << it << ". " << number << std::endl;
	}
	return;
}

void OddEvenSort(std::vector<int> &data)
{
	bool isSorted = false;

	while (!isSorted)
	{
		isSorted = true;

		for (uint32_t i = 1; i <= data.size() - 2; i += 2)
		{
			if (data.at(i) > data.at(i + 1))
			{
				std::swap(data.at(i), data.at(i + 1));
				isSorted = false;
			}
		}

		for (uint32_t i = 0; i <= data.size() - 2; i += 2)
		{
			if (data.at(i) > data.at(i + 1))
			{
				std::swap(data.at(i), data.at(i + 1));
				isSorted = false;
			}
		}
	}

	return;
}

void Sort()
{
	std::srand(std::time(nullptr));
	std::vector<int> data;
	uint16_t size, randFloor;

	std::cout << "Сколько элементов массива сгенерировать?" << std::endl;
	std::cin >> size;
	std::cout << "Введите верхний предел случайных элементов" << std::endl;
	std::cin >> randFloor;

	for (auto i = 0; i < size; ++i)
		data.push_back(std::rand() % randFloor);

	std::cout << "Массив до сортировки:" << std::endl;

	PrintIntegersVec(data);

	OddEvenSort(data);

	std::cout << "\n\nМассив после сортировки:" << std::endl;

	PrintIntegersVec(data);

	return;
}
