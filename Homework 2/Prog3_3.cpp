#include <iostream>
#include <fstream>
#include "Constants.h"
//�������� �������� �����
//�������

void Prog3_3()
{
    char c;
    std::fstream fs(file);
    std::string answer;

    if (!fs.is_open())
    {
        std::cout << "���� �� ��������" << std::endl;
        return;
    }

    while (fs.get(c))
        answer += c;


    fs.close();

    if (answer.empty()) std::cout << "���� ����." << std::endl;
    std::cout << answer << std::endl;
}