#include <iostream>
#include <vector>

void Series()
{
	double x, eps;
	uint32_t minIndex = 14;
	std::vector < double > seriesValue;

	std::cout << "\n\n��������� ��� ���������� ������� ����." << std::endl;

	std::cout << "������� ����� x." << std::endl;
	std::cin >> x;
	std::cout << "������� ����� �������" << std::endl;
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
			std::cout << "������ ������� " << seriesValue.at(i) << " ��� ������� " << i << std::endl;
			break;
		}
		if (i == 1'000'000)
		{
			std::cout << "������� ������� �� ������ �� ������� ��������" << std::endl;
		}
	}
	return;
}
