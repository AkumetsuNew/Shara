#include <iostream>
#include <cmath>
//��������
//�������

void Prog2_5() 
{
    double x = -4, step = 0.5;

    for (x; x <= 4; x += step) 
    {
        std::cout << "�������� ������� ��� x ������ " << x << ":" << std::endl;

        if (x == 1)
        {
            std::cout << "������������" << std::endl;
            continue;
        }

        std::cout << ((pow(x, 2) - 2 * x + 2) / (x - 1)) << std::endl;
    }
    return;
}