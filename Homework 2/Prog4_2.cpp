#include <iostream>

int Sign(double x)
{
    if (x < 0) return -1;
    if (x == 0) return 0;
    if (x > 0) return 1;
}

void Prog4_2()
{
    double num;

    std::cout << "Введите число:" << std::endl;
    std::cin >> num;

    std::cout << "Знак числа:\n" << Sign(num);
}