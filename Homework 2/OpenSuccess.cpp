#include "OpenSuccess.h"

bool OpenSuccess(std::fstream& fs)
{
    if (!fs.is_open())
    {
        std::cout << "Не удалось открыть файл." << std::endl;
        return false;
    }
    return true;
}