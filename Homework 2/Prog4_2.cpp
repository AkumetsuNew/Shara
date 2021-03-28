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

    std::cout << "¬ведите число:" << std::endl;
    std::cin >> num;

    std::cout << "«нак числа:\n" << Sign(num);
}