#include <iostream>

void FindGCD(int &num1, int &num2) // ���������� � ������� ����� ������� �� ������� �� �������
{
	if (num1 > num2)
		num1 %= num2;
	else
		num2 %= num1;
	return;
}

void Prog5_1()
{
	int num1, num2;

	std::cout << "�������� ������� ��� ���������� ����������� ������ �������� ���� ����� �����.\n" << std::endl;
	std::cout << "������� ������ �����:" << std::endl;
	std::cin >> num1;
	std::cout << "������� ������ �����:" << std::endl;
	std::cin >> num2;

	// �������� �����
	if (num1 <= 0 || num2 <= 0)
	{
		std::cout << "����� ������ ���� ������ ����." << std::endl;
		return;
	}


	while (num1 != 0 && num2 != 0)
		FindGCD(num1, num2); // � ����� ����� ���� ���������� ����� ����� ���, ������ � ����


	std::cout << "���������� ����� ��������:" << std::endl;
	std::cout << num1 + num2;
	// ����� ��� + 0 = ���
	return;
}