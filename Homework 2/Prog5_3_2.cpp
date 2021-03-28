#include "Constants.h"
#include "OpenSuccess.h"
#include <windows.h>
// ������� 36

//#include <filesystem>
//namespace fs = std::filesystem;

void ClearAndRefill(std::fstream& filestr)
{
	// �������� ����� �� ������ � ������� �����
	filestr.open(file3, std::fstream::out | std::fstream::trunc);

	// �������� ��������
	if (!OpenSuccess(filestr))
		return;

	// ���������� ����� ��������� �������
	filestr << fileFill;

	// �������� �����
	filestr.close();
}


// find ���������� npos, ���� �� ������ ��������������� �������
// � ������ ������ �� ���� � ������ ����������� �������� ������� c
// ���������� true, ���� ����� ������� ���� � false, ���� ���
bool IsExclusion(char c, const std::string& exclude)
{
	size_t a = exclude.find(c);

	if (a != std::string::npos)
		return true;

	return false;
}

void EraseExclusions(std::string& word, std::string& result, const std::string& exclude)
{
	bool wasExcluded = false;
	// �� ������ �������� ����� �������� �� ����������������,
	// ������ ���� ������� �� ������, ����� ��������� 
	// ���������������� ��������
	for (auto strIt = word.begin(); strIt != word.end(); strIt++)
	{
		if (!(wasExcluded = IsExclusion(*strIt, exclude)))
			result += *strIt;
	}
}

void Prog5_3_2() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::fstream filestr;
	std::string exclude, word, result;

	// ������� � ���������� �����
	ClearAndRefill(filestr);

	std::cout << "������� �������, ������� ������ ��������� �� �����" << std::endl;
	std::cin >> exclude;

	// �������� ����� �� ������ � ������
	filestr.open(file3, std::fstream::in | std::fstream::out | std::fstream::binary);

	// �������� ��������
	if (!OpenSuccess(filestr))
		return;

	// ��������� ������ � ������
	while (filestr >> word)
	{
		result += '\n';
		EraseExclusions(word, result, exclude);
	}

	
	//fs::resize_file(file3, 0);
	//filestr.seekp(0);

	filestr.close();
	// ������� �����
	filestr.open(file3, std::fstream::trunc);
	if (!OpenSuccess(filestr))
		return;

	filestr.close();

	// ��������� �������� ������ � ����
	filestr.open(file3);
	if (!OpenSuccess(filestr))
		return;

	filestr.write("�������� ������: ", 17);
	filestr.write(result.c_str(), result.length());

	filestr.close();

	// ����������� �������� ������ � �������
	std::cout << "\n�������� ������:"
		<< result << std::endl;
	return;
}