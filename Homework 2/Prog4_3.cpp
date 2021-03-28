#include <iostream>
#include <cmath>
#include "Constants.h"
//Выбор фигуры
//Сделано

double RecArea(double a, double b)
{
    return a * b;
}

double TriArea(double a, double b, double c)
{
    double area, half = (a + b + c) / 2;
    area = sqrt(half * (half - a) * (half - b) * (half - c));
    return area;
}

double CirArea(double r)
{
    double area = PI * pow(r, 2);
    return area;
}

bool ArePositiveValues(double a, double b = 1, double c = 1)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        std::cout << "Значения должны быть положительными." << std::endl;
        return false;
    }
    return true;
}

bool IsValidTriangle(double a, double b, double c)
{
    if (!(a < b + c && b < a + c && c < a + b))
    {
        std::cout << "Неправильно введены стороны треугольника." << std::endl;
        return false;
    }
    return true;
}

void Prog4_3()
{
    double recLen, recWid, triSid1, triSid2, triSid3, cirRad;
    bool isValid = true;
    int switcher = 0;

    std::cout << "Площадь какой фигуры вычислить?" << std::endl
        << "1. Прямоугольник" << std::endl
        << "2. Треугольник" << std::endl
        << "3. Круг" << std::endl;
    std::cin >> switcher;
    
    switch (switcher)
    {
    case 1:
        //Прямоугольник
        std::cout << "Введите длину прямоугольника" << std::endl;
        std::cin >> recLen;
        std::cout << "Введите ширину прямоугольника" << std::endl;
        std::cin >> recWid;
        isValid = ArePositiveValues(recLen, recWid);
        if (isValid)
            std::cout << "Площадь прямоугольника:" << std::endl
            << RecArea(recLen, recWid) << std::endl;
        //Прямоугольник
        break;

    case 2:
        //Треугольник
        std::cout << "\nВведите первую сторону треугольника" << std::endl;
        std::cin >> triSid1;
        std::cout << "Введите вторую сторону треугольника" << std::endl;
        std::cin >> triSid2;
        std::cout << "Введите третью сторону треугольника" << std::endl;
        std::cin >> triSid3;
        isValid = ArePositiveValues(triSid1, triSid2, triSid3) &&
            IsValidTriangle(triSid1, triSid2, triSid3);
        if (isValid)
            std::cout << "Площадь треугольника:" << std::endl
            << TriArea(triSid1, triSid2, triSid3) << std::endl;
        //Треугольник
        break;

    case 3:
        //Круг
        std::cout << "\nВведите радиус круга:" << std::endl;
        std::cin >> cirRad;
        isValid = ArePositiveValues(cirRad);
        if (isValid)
            std::cout << "Площадь круга:" << std::endl
            << CirArea(cirRad) << std::endl;
        //Круг
        break;

    default: 
        std::cout << "Нет такой фигуры." << std::endl;
    }

    return;
}