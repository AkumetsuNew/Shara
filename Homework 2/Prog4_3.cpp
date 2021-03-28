#include <iostream>
#include <cmath>
#include "Constants.h"
//����� ������
//�������

double RecArea(double a, double b)
{
    return a * b;
}

double TriArea(double a, double b, double c)
{
    double area, half = (a + b + c) / 2;
    area = sqrt(half * (half - a) * (half - b) * (half - c));
    return area;
}

double CirArea(double r)
{
    double area = PI * pow(r, 2);
    return area;
}

bool ArePositiveValues(double a, double b = 1, double c = 1)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        std::cout << "�������� ������ ���� ��������������." << std::endl;
        return false;
    }
    return true;
}

bool IsValidTriangle(double a, double b, double c)
{
    if (!(a < b + c && b < a + c && c < a + b))
    {
        std::cout << "����������� ������� ������� ������������." << std::endl;
        return false;
    }
    return true;
}

void Prog4_3()
{
    double recLen, recWid, triSid1, triSid2, triSid3, cirRad;
    bool isValid = true;
    int switcher = 0;

    std::cout << "������� ����� ������ ���������?" << std::endl
        << "1. �������������" << std::endl
        << "2. �����������" << std::endl
        << "3. ����" << std::endl;
    std::cin >> switcher;
    
    switch (switcher)
    {
    case 1:
        //�������������
        std::cout << "������� ����� ��������������" << std::endl;
        std::cin >> recLen;
        std::cout << "������� ������ ��������������" << std::endl;
        std::cin >> recWid;
        isValid = ArePositiveValues(recLen, recWid);
        if (isValid)
            std::cout << "������� ��������������:" << std::endl
            << RecArea(recLen, recWid) << std::endl;
        //�������������
        break;

    case 2:
        //�����������
        std::cout << "\n������� ������ ������� ������������" << std::endl;
        std::cin >> triSid1;
        std::cout << "������� ������ ������� ������������" << std::endl;
        std::cin >> triSid2;
        std::cout << "������� ������ ������� ������������" << std::endl;
        std::cin >> triSid3;
        isValid = ArePositiveValues(triSid1, triSid2, triSid3) &&
            IsValidTriangle(triSid1, triSid2, triSid3);
        if (isValid)
            std::cout << "������� ������������:" << std::endl
            << TriArea(triSid1, triSid2, triSid3) << std::endl;
        //�����������
        break;

    case 3:
        //����
        std::cout << "\n������� ������ �����:" << std::endl;
        std::cin >> cirRad;
        isValid = ArePositiveValues(cirRad);
        if (isValid)
            std::cout << "������� �����:" << std::endl
            << CirArea(cirRad) << std::endl;
        //����
        break;

    default: 
        std::cout << "��� ����� ������." << std::endl;
    }

    return;
}