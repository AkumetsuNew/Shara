#include <iostream>
#include <cmath>
#include "Constants.h"

double CalcDist(double r, double S, double n, double m) 
{
    double diff = abs(m - (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1)));
    return diff;
}

bool CheckForClosest(double r, double S, double n, double m,
    double &diff, double &diffnext, double diffprev)
{
    double rnext = r + EPSILON;
    bool isClosest = false;

    diff = CalcDist(r, S, n, m);
    diffnext = CalcDist(rnext, S, n, m);

    r - EPSILON == 0 ? isClosest = (diff < diffnext) : isClosest = ((diff < diffnext) && (diff < diffprev));

    return isClosest;
}

void Prog3_2() 
{
    double S, n, m, r = 0, rnext, p = 0, diff, diffprev = 0, diffnext;
    bool isClosest;

    std::cout << "Введите сумму займа:" << std::endl;
    std::cin >> S;
    if (S <= 0)
    {
        std::cout << "Неправильная сумма займа" << std::endl;
        return;
    }

    std::cout << "Введите срок займа (в годах):" << std::endl;
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "Неправильный срок займа";
        return;
    }

    std::cout << "Введите месячную выплату займа:" << std::endl;
    std::cin >> m;
    if (m <= 0)
    {
        std::cout << "Неправильная месячная выплата" << std::endl;
        return;
    }

    while (!p) 
    {
        r += EPSILON;

        isClosest = CheckForClosest(r, S, n, m, diff, diffnext, diffprev);
        if (isClosest) p = 100 * r;

        diffprev = diff;
    }

    

    std::cout << "Процент займа: \n" << p << std::endl;
    return;
}
