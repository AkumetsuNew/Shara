#include <iostream>


void Prog2_4() 
{
    double n;
    int a;
    bool c;

    std::cout << "Введите целое число:" << std::endl;
    std::cin >> n;

    if (n != (long long)n)
    {
        std::cout << "Число не целое";
        return;
    }

    std::cout << "Введите интервал:" << std::endl;
    std::cin >> a;
    if (a <= 0)
    {
        std::cout << "Интервал должен быть положительным" << std::endl;
        return;
    }

    std::cout << "Введите 1, если отсчёт ведётся вперёд или 0, если назад:" << std::endl;
    std::cin >> c;

    int c1 = n + a, c0 = n - a;

    std::cout << "Ответ:" << std::endl;

    for (n; c ? n < c1 : n > c0; c ? n++ : n--) 
        std::cout << n << std::endl;

    return;
}