#include <iostream>
#include <regex>
#include <map>
#include "Constants.h"

void Prog4_6()
{

    std::regex romeChecker(romeex,
        std::regex_constants::ECMAScript);

    std::string romeNum;
    int sum = 0;

    std::map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

    std::cout << "Введите римское число:" << std::endl;
    std::cin >> romeNum;
    if (!std::regex_search(romeNum, romeChecker))
    {
        std::cout << "Неправильное число." << std::endl;
        return;
    }


    for (auto i = 0; i < romeNum.length(); i++)
    {
        if (m[romeNum[i + 1]] <= m[romeNum[i]]) sum += m[romeNum[i]];
        else  sum -= m[romeNum[i]];
    }

    std::cout << "Арабский эквивалент:" << std::endl
        << sum << std::endl;
    return;
}