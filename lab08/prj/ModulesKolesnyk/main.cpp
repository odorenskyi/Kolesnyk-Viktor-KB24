#include <iostream>
#include <cmath>
#include "ModulesKolesnyk.h"

using namespace std;

double s_calculation(double x, double y, double z) {
    if (z < 0) {
        cout << "Помилка: значення z не може бути від'ємним." << endl;
        return NAN;
    }
    double num = pow(x, 2) - pow(y, 3);
    double den = 12 * x + pow(y, 2) - M_PI * sqrt(z);

    if (den == 0) {
        cout << "Помилка: знаменник не може бути нульовим." << endl;
        return NAN;
    }
    return num + sqrt(abs(z * exp(x)) / den);
}

SalaryInfo calculateBonus(double salary, int years) {
    SalaryInfo info;

    if (salary <= 0) {
        cout << "Помилка: зарплата повинна бути більше нуля" << endl;
        info.bonusPercent = 0;
        info.totalWithBonus = 0;
        return info;
    }
    if (years < 0) {
        cout << "Помилка: стаж роботи не може бути від'ємним" << endl;
        info.bonusPercent = 0;
        info.totalWithBonus = 0;
        return info;
    }
    if (years >= 2 && years < 5)
        info.bonusPercent = 5;
    else if (years >= 5 && years < 10)
        info.bonusPercent = 10;
    else if (years >= 10)
        info.bonusPercent = 25;
    else
        info.bonusPercent = 0;
    info.totalWithBonus = salary + (salary * info.bonusPercent / 100.0);
    return info;
}


string helmetSize(int head) {
    if (head >= 53 && head <= 54)
        return "XS";
    else if (head >= 55 && head <= 56)
        return "S";
    else if (head >= 57 && head <= 58)
        return "M";
    else if (head >= 59 && head <= 60)
        return "L";
    else if (head >= 61 && head <= 62)
        return "XL";
    else
        return "Некоректне значення обхвату голови";
}

BinaryResult analyzeBinary(unsigned int number) {
    BinaryResult result;

    if (number > 40008050 || number < 0) {
        cout << "Помилка: число повинно бути у межах від 0 до 40008050." << endl;
        result.bit16Value = false;
        result.countMatching = -1;
        return result;
    }
    result.bit16Value = (number >> 15) & 1;
    result.countMatching = 0;

    for (int i = 0; i < 32; ++i) {
        result.countMatching += (result.bit16Value)
        ? (((number >> i) & 1) == 0) ? 1 : 0
        : (((number >> i) & 1) == 1) ? 1 : 0;
    }
    return result;
}
