#include <iostream>


void Prog2_4() 
{
    double n;
    int a;
    bool c;

    std::cout << "������� ����� �����:" << std::endl;
    std::cin >> n;

    if (n != (long long)n)
    {
        std::cout << "����� �� �����";
        return;
    }

    std::cout << "������� ��������:" << std::endl;
    std::cin >> a;
    if (a <= 0)
    {
        std::cout << "�������� ������ ���� �������������" << std::endl;
        return;
    }

    std::cout << "������� 1, ���� ������ ������ ����� ��� 0, ���� �����:" << std::endl;
    std::cin >> c;

    int c1 = n + a, c0 = n - a;

    std::cout << "�����:" << std::endl;

    for (n; c ? n < c1 : n > c0; c ? n++ : n--) 
        std::cout << n << std::endl;

    return;
}