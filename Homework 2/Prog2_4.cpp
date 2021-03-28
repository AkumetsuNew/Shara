#include <iostream>


void Prog2_4() 
{
    double n;
    int a;
    bool c;

    std::cout << "¬ведите целое число:" << std::endl;
    std::cin >> n;

    if (n != (long long)n)
    {
        std::cout << "„исло не целое";
        return;
    }

    std::cout << "¬ведите интервал:" << std::endl;
    std::cin >> a;
    if (a <= 0)
    {
        std::cout << "»нтервал должен быть положительным" << std::endl;
        return;
    }

    std::cout << "¬ведите 1, если отсчЄт ведЄтс€ вперЄд или 0, если назад:" << std::endl;
    std::cin >> c;

    int c1 = n + a, c0 = n - a;

    std::cout << "ќтвет:" << std::endl;

    for (n; c ? n < c1 : n > c0; c ? n++ : n--) 
        std::cout << n << std::endl;

    return;
}