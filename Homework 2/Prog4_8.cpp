#include <iostream>
#include <time.h>
#include <iomanip>
#include "Constants.h"

template <size_t rows, size_t cols>
void MatrixPrint(double (&tab)[rows][cols])
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
            std::cout << std::setw(10) << tab[i][j];
        std::cout << "\n";
    }
    std::cout << std::endl;
}

template <size_t rows1, size_t cols1,
    size_t rows2, size_t cols2,
    size_t rows3, size_t cols3>
void MatrixMult(double(&tab1)[rows1][cols1],
    double(&tab2)[rows2][cols2],
    double(&restab)[rows3][cols3])
{
    for (auto i = 0; i < rows1; i++)
        for (auto j = 0; j < cols2; j++)
            for (auto k = 0; k < cols1; k++)
                restab[i][j] += tab1[i][k] * tab2[k][j];
}

template <size_t rows, size_t cols>
void MinMaxTotalSearch(double(&tab)[rows][cols], double &total, double &max,
    int &maxIndex, double &min, int &minIndex, const int moneyOrCom)
{
    for (auto i = 0; i < rows; i++)
    {
        if (max < tab[i][moneyOrCom])
        {
            max = tab[i][moneyOrCom];
            maxIndex = i + 1;
        }
        if (min > tab[i][moneyOrCom])
        {
            min = tab[i][moneyOrCom];
            minIndex = i + 1;
        }
        total += tab[i][moneyOrCom];
    }
}

void Prog4_8() {
    double A[3][4] = tabA;
    double B[4][2] = tabB;
    double C[3][2] = { 0 };

    std::cout << "������� �:" << std::endl;
    MatrixPrint(A);

    std::cout << "������� B:" << std::endl;
    MatrixPrint(B);

    std::cout << "������� C:" << std::endl;
    MatrixMult(A, B, C);
    MatrixPrint(C);

    double maxMoney = 0, minMoney = C[1][0], totalMoney = 0;
    int maxMoneyIndex, minMoneyIndex;
    MinMaxTotalSearch(C, totalMoney, maxMoney, maxMoneyIndex, minMoney, minMoneyIndex, 0);

    double maxCom = 0, minCom = C[1][1], totalCom = 0;
    int maxComIndex, minComIndex;
    MinMaxTotalSearch(C, totalCom, maxCom, maxComIndex, minCom, minComIndex, 1);

    double total = totalCom + totalMoney;

    std::cout << "\n������ ����� � ������� ������� �������� �" << maxMoneyIndex
        << ", � ������ � " << maxMoney << " ������\n"
        << "������ ����� ������� �������� �" << minMoneyIndex
        << ", � ������ � " << minMoney << " ������\n" << std::endl;

    std::cout << "������ ����� ������������ ������� �������� �" << maxComIndex
        << ", � ������ � " << maxCom << " ������\n"
        << "������ ����� ������� �������� �" << minComIndex
        << ", � ������ � " << minCom << " ������\n" << std::endl;


    std::cout << "����� �������:\n" << totalMoney << " ������\n"
        << "����� ������������:\n" << totalCom << " ������\n"
        << "����� ����� ������:\n" << total << " ������" << std::endl;
    return;
}