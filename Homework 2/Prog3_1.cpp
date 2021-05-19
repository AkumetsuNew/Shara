#include <iostream>
#include <cmath>
// Исправить проценты не больше 100
// Сделано

void Prog3_1() 
{
    double S, n, p;

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

    std::cout << "Введите процент займа:" << std::endl;
    std::cin >> p;
    if (p <= 0 || p > 100)
    {
        std::cout << "Неправильный процент займа" << std::endl;
        return;
    }

    double r = p / 100;
    float m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));


    std::cout << "Ежемесячная выплата:\n" << m << std::endl;
    return;
}
