#include <iostream>
#include <fstream>
#include "Constants.h"
//�������� �������� �����
//�������

std::string Prog3_4()
{
    char c;
    std::string answer;
    std::fstream fs(file2);

    if (!fs.is_open())
        return "���� �� ��������";

    while (fs.get(c))
        if (isdigit(c)) answer += c;

    fs.close();

    if (answer.empty()) return "��� ����.";
    return answer;
}