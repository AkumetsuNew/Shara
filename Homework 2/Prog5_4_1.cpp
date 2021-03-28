#include <iostream>
#include <cmath>
#include <vector>
// ������� 10

// ������� �������� �������� ����������� ��� ������������ �������������
void CacheFactorial(std::vector<uint64_t>& facCache, const uint16_t& termAmount)
{
	for (auto i = 1; i <= termAmount; i++)
	{
		facCache[i] = (facCache[i - 1] * i);
	}
	return;
}


// ������� ������������ � �������� �������� �������
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


	std::cout << "���������:\n"
		<< result << std::endl;
	return;
}

void Prog5_4_1()
{
	uint16_t n;

	std::cout << "\n���������� ����� ����.\n" << std::endl;
	std::cout << "������� ����� ���������" << std::endl;
	std::cin >> n;

	// ��������� �����
	if (n < 1)
	{
		std::cout << "� ���� ������ ���� ���� �� ���� ���������" << std::endl;
		return;
	}
	if (n > 244)
	{
		std::cout << "���������� ��������� ������ 244 ��������� (�� ������� ���� �� ���� ������)" << std::endl;
		return;
	}

	// ����� �������, ������� ���� ����� ����
	SeriesSum(n);
	return;
}