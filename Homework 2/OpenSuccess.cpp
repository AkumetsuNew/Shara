#include "OpenSuccess.h"

bool OpenSuccess(std::fstream& fs)
{
    if (!fs.is_open())
    {
        std::cout << "�� ������� ������� ����." << std::endl;
        return false;
    }
    return true;
}