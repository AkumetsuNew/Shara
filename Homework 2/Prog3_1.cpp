#include <iostream>
#include <string>
#include <cmath>
// ��������� �������� �� ������ 100
// �������

std::string Prog3_1() 
{
    double S, n, p;

    std::cout << "������� ����� �����:" << std::endl;
    std::cin >> S;
    if (S <= 0) return "������������ ����� �����";

    std::cout << "������� ���� ����� (� �����):" << std::endl;
    std::cin >> n;
    if (n <= 0) return "������������ ���� �����";

    std::cout << "������� ������� �����:" << std::endl;
    std::cin >> p;
    if (p <= 0 || p > 100) return "������������ ������� �����";

    double r = p / 100;
    float m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

    std::string mret(std::to_string(m));

    std::cout << "����������� �������:" << std::endl;
    return mret;
}