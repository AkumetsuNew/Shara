#include "OpenSuccess.h"
#include <Windows.h>
#include <string>
#include <set>

const char firstRusLet = -65;
const char lastRusCapitalLet = -33;
const char lastRusLet = -1;
const std::string numbers = "0123456789";
//const uint16_t winLen1251 = 256;

// ���������� true, ���� ������� ����� ����/�������
bool InputIsStop(const std::string& input)
{
	std::set<std::string> stopStrings
	{
		"Stop", "stop", "s", "S",
		"����", "����", "�", "�"
	};
	if (stopStrings.count(input))
		return true;
	return false;
}

bool IsNotCapital(const char& c)
{
	if (c < firstRusLet || c > lastRusCapitalLet)
		return true;
	else
		return false;
}

bool IsNotAlphaRussian(const char& c)
{
	if (c == '-' || c == '�' || c == '�') return false;
	if (c < firstRusLet || c > lastRusLet)
		return true;
	else
		return false;
}

// ���������� true, ���� ���� �� �������� �������
bool InputIsInvalid(const std::string& input)
{
	const size_t idWidth = (6 - 1);
	// �������� ��������, ������ ���� ����� ����
	if (input.find_first_of(' ') != input.find_last_of(' ') // �������� 1: ������ ������ ��������
		||													// ���
		input.find_first_of(' ') == std::string::npos)		// �������� 2: ��� ��������
	{
		std::cout << "� ������ ������ ���� ����� ���� ������." << std::endl;
		return true;
	}

	// ������� ������ �����, ������ ���� ������� ���������
	if (IsNotCapital(*input.begin()))
	{
		std::cout << "������ ����� ������ ���� ������� ���������." << std::endl;
		return true;
	}

	auto spacePosIt = input.begin() + input.find_first_of(' ');

	// �������� ������� "�����"(�� �������), ������ �������� �� ������� ����
	for (auto strIt = input.begin() + 1; strIt != spacePosIt; ++strIt)
	{
		
		if (IsNotAlphaRussian(*strIt))
		{
			std::cout << "������� ������ �������� �� ������� ����." << std::endl;
			return true;
		}
	}

	// ��������� ���������� ����, ������ ���� �����
	if (input.find_last_of(numbers) - input.find_first_of(numbers) != idWidth)
	{
		std::cout << "���� ������ �������� ����� �� ����� ����." << std::endl;
		return true;
	}

	auto firstNumPosIt = input.begin() + input.find_first_of(numbers);
	auto lastNumPosIt = input.begin() + input.find_last_of(numbers);
 	
	// ���������, ��� ��������� ����� � ��������� ������� ������
	if (lastNumPosIt + 1 != input.end())
	{
		std::cout << "���� ������ ������������� ������" << std::endl;
		return true;
	}

	// ���������, ��� ����� ������ � ��������� ������ ������ �����
	for (auto strIt = firstNumPosIt; strIt != input.end(); strIt++)
	{
		if (!isdigit(*strIt))
		{
			std::cout << "���� ������ �������� �� ����" << std::endl;
			return true;
		}
	}
	return false;
}

// ���� ������
bool Input(std::string& inputWhole)
{
	std::string inputStr = inputWhole;
	if (inputStr.empty())
		std::cout << "������ �� ������ ������� ������.\n"
			<< "������ ������:\n"
			<< "<������� � ��������� ����� ����������><������><������ �� ����� ����>\n"
			<< "����� ������������, �������� ���� ��� �\n"
			<< std::endl;

	while (true)
	{
		std::cout << "������� ������� � ���� �������� ����� ������:\n" << std::endl;

		// ��� ���������� ������ getline, ���������� � ������ �����
		if (inputStr.empty())
			std::cin.ignore();

		std::getline(std::cin, inputStr);

		//std::cout << inputStr << std::endl;
		//std::cout << "\n" << inputStr << "\n";

		//for (auto it = inputStr.begin(); it != inputStr.end(); it++)
		//	std::cout << (int)*it << " " << *it << std::endl;


		// ���������, ����� �� ������������ ������������
		if (InputIsStop(inputStr)) break;
		// ��������� ������������ �����
		if (InputIsInvalid(inputStr)) return false;

		
		

		inputWhole += inputStr + '\n';
	}

	return true;
}

void Prog5_5()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::fstream fs;
	std::string inputWhole;

	std::cout << "\n��������� ��� ����� � ��������� ������ ���������\n" << std::endl;

	while (!Input(inputWhole))
		std::cout << "������������ ����, ���������� �����\n\n" << std::endl;

	std::cout << "\n" << inputWhole;
}