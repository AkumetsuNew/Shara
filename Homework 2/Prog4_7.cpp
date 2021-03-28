#include <iostream>
#include <time.h>
#include <iomanip>
#include "Constants.h"
//������� ��� 2 �������
int RanNumGen(int s, int var) 
{
    int m, i, c;
    if (var == 1)
    {
        m = 37;
        i = 3;
        c = 64;
    }
    if (var == 2)
    {
        m = 25173;
        i = 13849;
        c = 65537;
    }
    s = (m * s + i) % c;

    return s;
}

void RanNumPrint(int &firstNum, int itCount, const int var)
{
    int i = 1;

    while (itCount)
    {
        std::cout << "��������� ����� �" << i << ":"
            << std::endl << firstNum << std::endl;
            firstNum = RanNumGen(firstNum, var);

        i++;
        itCount--;
    }
}

void Prog4_7() 
{
    int s1, s2, itCount;
    std::srand(time(NULL));

    std::cout << "������� ����� �������� ������������." << std::endl;
    std::cin >> itCount;

    if (itCount <= 0)
    {
        std::cout << "\n����� �������� ������ ���� �������������." << std::endl;
        return;
    }

    s1 = std::rand() % var1Mod;
    s2 = std::rand() % var2Mod;

    std::cout << "\n������� 1:" << std::endl;
    RanNumPrint(s1, itCount, 1);

    std::cout << "\n������� 2:" << std::endl;
    RanNumPrint(s2, itCount, 2);

    return;
}