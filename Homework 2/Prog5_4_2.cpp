#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
// ������� 36

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

	std::cout << "\n��������� ��� ���������� ������ ��������� �����\n" << std::endl;


	std::cout << "������� ����� ����������� ��������:" << std::endl;
	std::cin >> n;
	
	std::cout << "������� ������ �� �������, ������������ ��������:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, inputStr);
	
	// ���������� ��������� ������
	std::cout << "\n����� ���������� ������:\n"
		<< inputStr.substr(0, n) << std::endl;

	// ������ ������ ������� � ��������� � ���� ������ (��� � �����)
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

	// ��������� ����� �������� �����, ���� �������� ������� �� �� �������
	// ���� �������� �� ������� ��� ��������� ������� ��������� -- ����� �������
	// ���������� � ����������� ����� ����������� �� �������� ����� � ����������� ������������
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
	
	std::cout << "����� ������ ��������� �����:\n"
		<< minWord << std::endl;
	return;
}