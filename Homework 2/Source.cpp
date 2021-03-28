#include <iostream>
#include <map>
#include "Prototypes.h"

enum string_code
{
    eDefault,
    eProg2_4,
    eProg2_5,
    eProg3_1,
    eProg3_2,
    eProg3_3,
    eProg3_4,
    eProg3_5,
    eProg4_1,
    eProg4_2,
    eProg4_3,
    eProg4_4,
    eProg4_5,
    eProg4_6,
    eProg4_7,
    eProg4_8,
    eProg4_9,
    eProg5_1,
    eProg5_2,
    eProg5_3_1,
    eProg5_3_2,
    eProg5_4_1,
    eProg5_4_2,
    eProg5_5
};

string_code hashStringtoEnum(std::string const& inString)
{
    if (inString == "2.4") return eProg2_4;
    if (inString == "2.5") return eProg2_5;
    if (inString == "3.1") return eProg3_1;
    if (inString == "3.2") return eProg3_2;
    if (inString == "3.3") return eProg3_3;
    if (inString == "3.4") return eProg3_4;
    if (inString == "3.5") return eProg3_5;
    if (inString == "4.1") return eProg4_1;
    if (inString == "4.2") return eProg4_2;
    if (inString == "4.3") return eProg4_3;
    if (inString == "4.4") return eProg4_4;
    if (inString == "4.5") return eProg4_5;
    if (inString == "4.6") return eProg4_6;
    if (inString == "4.7") return eProg4_7;
    if (inString == "4.8") return eProg4_8;
    if (inString == "4.9") return eProg4_9;
    if (inString == "5.1") return eProg5_1;
    if (inString == "5.2") return eProg5_2;
    if (inString == "5.3.1") return eProg5_3_1;
    if (inString == "5.3.2") return eProg5_3_2;
    if (inString == "5.4.1") return eProg5_4_1;
    if (inString == "5.4.2") return eProg5_4_2;
    if (inString == "5.5") return eProg5_5;
    return eDefault;
}

int main()
{
    setlocale(LC_ALL, "rus");

    bool repeatAll = true;
    std::string progNum, repeat;
    std::map<std::string, bool> YesNo
    {
        {"Yes", true}, {"yes", true}, {"Y", true}, {"y", true},
        {"No", false}, {"no", false}, {"N", false}, {"n", false} 
    };

    while (repeatAll)
    {
        std::cin.clear();
        std::cout << "\n\nКакую программу запустить?" << std::endl;
        std::cin >> progNum;
        std::cout << "\n\nВыполняется программа " << progNum << "\n" << std::endl;

        switch (hashStringtoEnum(progNum))
        {
        case eProg2_4:
            Prog2_4();
            break;
        case eProg2_5:
            Prog2_5();
            break;
        case eProg3_1:
            std::cout << Prog3_1();
            break;
        case eProg3_2:
            std::cout << Prog3_2();
            break;
        case eProg3_3:
            Prog3_3();
            break;
        case eProg3_4:
            std::cout << Prog3_4();
            break;
        case eProg3_5:
            Prog3_5();
            break;
        case eProg4_1:
            Prog4_1();
            break;
        case eProg4_2:
            Prog4_2();
            break;
        case eProg4_3:
            Prog4_3();
            break;
        case eProg4_4:
            Prog4_4();
            break;
        case eProg4_5:
            Prog4_5();
            break;
        case eProg4_6:
            Prog4_6();
            break;
        case eProg4_7:
            Prog4_7();
            break;
        case eProg4_8:
            Prog4_8();
            break;
        case eProg4_9:
            Prog4_9();
            break;
        case eProg5_1:
            Prog5_1();
            break;
        case eProg5_2:
            Prog5_2();
            break;
        case eProg5_3_1:
            Prog5_3_1();
            break;
        case eProg5_3_2:
            Prog5_3_2();
            break;
        case eProg5_4_1:
            Prog5_4_1();
            break;
        case eProg5_4_2:
            Prog5_4_2();
            break;
        case eProg5_5:
            Prog5_5();
            break;


        case eDefault:
            __fallthrough;
        default:
            std::cout << "Нет такой программы." << std::endl;
            repeatAll = true;
        }
        std::cin.clear();
        std::cout << "\n\nВыбрать программу снова?(Yes/No)" << std::endl;
        std::cin >> repeat;
        repeatAll = YesNo[repeat];
    }
}