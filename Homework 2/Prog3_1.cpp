#include <iostream>
#include <string>
#include <cmath>
// Исправить проценты не больше 100
// Сделано

std::string Prog3_1() 
{
    double S, n, p;

    std::cout << "Введите сумму займа:" << std::endl;
    std::cin >> S;
    if (S <= 0) return "Неправильная сумма займа";

    std::cout << "Введите срок займа (в годах):" << std::endl;
    std::cin >> n;
    if (n <= 0) return "Неправильный срок займа";

    std::cout << "Введите процент займа:" << std::endl;
    std::cin >> p;
    if (p <= 0 || p > 100) return "Неправильный процент займа";

    double r = p / 100;
    float m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

    std::string mret(std::to_string(m));

    std::cout << "Ежемесячная выплата:" << std::endl;
    return mret;
}