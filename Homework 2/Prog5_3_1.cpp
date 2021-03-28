// ������� 10
#include "OpenSuccess.h"
#include <string>
#include <windows.h>

//const std::string consonants = "�����������������������";
const std::string vowels = "���������";
const std::string irregulars = "��";


// find ���������� npos, ���� �� ������ ��������������� �������
// � ������ ������ �� ���� � ������ ������� ������� c
// ���������� true, ���� ����� ������� ���� � false, ���� ���
bool IsVowel(char c)
{
    size_t a = vowels.find(c);

    if (a != std::string::npos)
        return true;

    return false;
}


// find ���������� npos, ���� �� ������ ��������������� �������
// � ������ ������ �� ���� � ������ ������������ ���� ������� c
// ���������� true, ���� ����� ������� ���� � false, ���� ���
bool IsIrregularLetter(char c)
{
    size_t a = irregulars.find(c);

    if (a != std::string::npos)
        return true;

    return false;
}

void AddToResult(std::string& word, std::string& result)
{
    size_t foundPos = word.find_first_of(vowels);
    size_t foundLast = 0;
    size_t foundNew;
    bool LastWasClosest = false;

    while (foundPos != std::string::npos)
    {

        // ���� ����� ��������� ������� ��������� ����� - �������
        // ��������� ���� �����, ���� ������� ���� �������
        // ��� ���, ���� ������� -- �� �������
        if (IsVowel(word[foundPos + 1]))
        {
            if (LastWasClosest)
                result += word.substr(foundLast, 1) + '-';
            else
                result += word.substr(foundLast, foundPos - foundLast + 1) + '-';

            foundLast = foundPos;
            LastWasClosest = true;
        }

        // ���� ������ ��� �������, ��������� ��, ��� ��������
        else if (word.find_first_of(vowels, foundPos + 1) == std::string::npos)
        {
            //substr � ����� ���������� ������� �� �����
            if (LastWasClosest)
                result += word.substr(foundPos);
            else
                result += word.substr(foundLast);
            break;
        }

        // ���� ��������� ������� ���������� ����� ���� �����
        // �� ����������� ������� � ��������� �����, ���� ������� ���� �������
        // ��� ����������, ������� � ���������, ���� ������� ���� ���������
        // ���� ����� ��������� ������� ����� � ��� �, �� �� ���� �����������
        else if (IsVowel(word[foundPos + 2]))
        {
            if (LastWasClosest)
                foundLast++;
            if (IsIrregularLetter(word[foundPos + 1]))
                foundPos++;
            result += word.substr(foundLast, foundPos - foundLast + 1) + '-';
            foundLast = foundPos + 1;
            LastWasClosest = false;
        }

        // ���� ��������� ������� ���������� ����� ��������� ����
        // �� ����������� ������� � ��������� ����� (�������� ���� ����� ��������� �������), ���� ������� ���� �������
        // ��� ����������, ������� � ���������, ���� ������� ���� ���������
        // ���� ����� ��������� ������� ����� � ��� �, �� �� ���� �����������
        else
        {
            foundNew = foundPos + 1;
            
            if (IsIrregularLetter(word[foundNew + 1]))
                foundNew++;
            if (LastWasClosest)
                foundLast++;
            // ���� ��������� ������� ������, ��� ����� ��� �����,
            // ����� ��������� ����� �� ��� ����� ������ ��������� �������
            result += word.substr(foundLast, foundNew - foundLast + 1) + '-';
            foundLast = foundNew + 1;
            LastWasClosest = false;
        }

        // ��������� ��������� ���������
        foundPos = word.find_first_of(vowels, foundPos + 1);
    }
    result += ' ';
}

void DivideBySyllables(std::fstream& fs)
{
    std::string result, word;

    // �������� AddToResult ��� ������� ����� (����� ������������ ��������)
    while (fs >> word)
        AddToResult(word, result);

    std::cout << result << std::endl;
}

// �������� ��������
//bool OpenSuccess(std::fstream& fs) 
//{
//    if (!fs.is_open())
//    {
//        std::cout << "�� ������� ������� ����." << std::endl;
//        return false;
//    }
//    return true;
//}

void Prog5_3_1()
{
    // ��� ������� �������� 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string FILENAME, inputarr;
    std::fstream fs;

    std::cout << "������� �������� �����:" << std::endl;
    std::cin >> FILENAME;
    FILENAME += ".txt";

    // �������� ����� �� ������
    fs.open(FILENAME, std::fstream::out);

    // �������� ��������
    if (!OpenSuccess(fs)) return;

    // ���������� � �������� �����
    std::cout << "������� �����:\n";
    std::cin.ignore();
    std::getline(std::cin, inputarr);
    fs << inputarr;
    
    // �������� �����
    fs.close();
    
    // �������� ����� �� ������
    fs.open(FILENAME, std::fstream::in);

    // �������� ��������
    if (!OpenSuccess(fs))
        return;

    // ����� � ����� ������
    DivideBySyllables(fs);
    
    // �������� �����
    fs.close();

    
    // �������� �����
    remove(FILENAME.c_str());
    return;
}
