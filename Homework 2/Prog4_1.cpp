#include <iostream>
#include <fstream>
#include <string>
//�������� �������� �����
//�������

void Prog4_1() 
{
    // �������� �����
    std::string FILENAME, inputarr, input;
    std::fstream fs;
    std::cout << "������� �������� �����:" << std::endl;
    std::cin >> FILENAME;
    FILENAME += ".txt";

    // ���������� �����
    fs.open(FILENAME, std::fstream::out);

    if (!fs.is_open())
    {
        std::cout << "���� �� ��������" << std::endl;
        return;
    }

    std::cout << "\n������� 10 ����� (���� ����� ������� ����� �������):" << std::endl;
    for (auto i = 0; i < 10; i++)
    {
        std::cout << "����� " << i + 1 << ":" << std::endl;
        std::cin >> input;
        inputarr += input + ' ';
    }
    fs << inputarr;
    fs.close();

    //������ �����
    double answer = 0;
    char c;
    std::string numbers;
    fs.open(FILENAME, std::fstream::in);

    if (!fs.is_open())
    {
        std::cout << "���� �� ��������" << std::endl;
        return;
    }

    while (fs.get(c)) 
    {
        if (isdigit(c) || c == '.' || c == '-' || c == ',')
        {
            numbers += c;
        }
        else
        {
            answer += stod(numbers);
            numbers.clear();
        }
    }
    fs.close();

    //����� ������
    std::cout << "����� ����� � �����:" << std::endl;
    std::cout << answer << std::endl;
}