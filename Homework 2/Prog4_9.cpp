#include <iostream>

#include "Constants.h"

std::string BaseChange(std::string number, int base, int newBase) 
{

    std::string numAll = numerals;
    int numDec = 0;
    std::string numRet;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        int power = number.length() - i - 1;
        for (auto j = 0; j < base; j++)
        {
            if (number[i] == numAll[j]) 
            {
                numDec += j * (int)pow(base, power);
                break;
            }
        }
    }

    int i = 0;
    while (numDec > 0)
    {
        int index = numDec % newBase;
        numRet += numAll[index];
        numDec /= newBase;
        i++;
    }

    std::string retNum(numRet.rbegin(), numRet.rend());

    return retNum;
}

bool BaseCheck(int base, std::string numAll)
{
    if (base <= 0 || base >= numAll.length())
    {
        std::cout << "ќснование должно быть больше нул€ и меньше 36." << std::endl;
        return false;
    }
    return true;
}

bool IsValidNumeral(int baseOld, std::string numOld, std::string numAll)
{
    bool isValidNumeral;
    for (auto i = 0; i < numOld.length(); i++)
    {
        isValidNumeral = false;
        for (auto j = 0; j < baseOld; j++)
        {
            if (numOld[i] == numAll[j])
            {
                isValidNumeral = true;
                break;
            }
        }
        if (!isValidNumeral)
        {
            std::cout << "¬ведена цифра, не соответствующа€ основанию." << std::endl;
            return false;
        }
    }
    return true;
}

void Prog4_9()
{
    std::string numOld, numNew, numAll = numerals;
    int baseOld, baseNew;
    bool noError = true;


    std::cout << "¬ведите основание системы счислени€:" << std::endl;
    std::cin >> baseOld;

    std::cout << "¬ведите число в заданном основании:" << std::endl;
    std::cin >> numOld;

    std::cout << "¬ведите основание новой системы счислени€:" << std::endl;
    std::cin >> baseNew;

    noError = 
        BaseCheck(baseNew, numAll) &&
        BaseCheck(baseOld, numAll) &&
        IsValidNumeral(baseOld, numOld, numAll);

    if (!noError)
        return;

    numNew = BaseChange(numOld, baseOld, baseNew);

    std::cout << "\n„исло " << numOld << "(" << baseOld << ") в основании "
        << baseNew << ":\n" << numNew << std::endl;
}