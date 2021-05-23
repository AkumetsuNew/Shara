#include <iostream>
#include <vector>

void StrucNum()
{
	uint32_t rangeStart, rangeEnd;
	std::cout << "\n\nѕрограмма дл€ нахождени€ чисел якобстал€ на интервале.";

	std::cout << "\n¬ведите натуральное число Ч начало интервала." << std::endl;
	std::cin >> rangeStart;
	std::cout << "¬ведите натуральное число больше чем предыдущее Ч конец интервала." << std::endl;
	std::cin >> rangeEnd;

	if (rangeStart > rangeEnd)
	{
		std::cout << "¬ы ввели числа в неправильном пор€дке, но программа исправила это" << std::endl;
		std::swap(rangeStart, rangeEnd);
	}
	std::vector<uint32_t> numberCache;

	for (uint32_t i = 0; i <= rangeEnd; i++)
	{
		if (i < 2)
		{
			numberCache.push_back(i);
			std::cout << i;
			continue;
		}
		std::cout << i;
		numberCache.push_back(numberCache.at(i - 1) + (2 * numberCache.at(i - 2)));
	}
	
	std::cout << "ќтображаютс€ числа якобстал€ с " << rangeStart << " до " << rangeEnd << std::endl;
	for (auto range = rangeStart; range <= rangeEnd; range++)
	{
		std::cout << range << ". " << numberCache.at(range) << std::endl;
	}

	return;
}
