#ifndef MODULESKOLESNYK_H_INCLUDED
#define MODULESKOLESNYK_H_INCLUDED
#include <string>
#include <cmath>

using namespace std;

struct SalaryInfo {
    double bonusPercent;
    double totalWithBonus;
};

struct BinaryResult {
    bool bit16Value;
    int countMatching;
};

double s_calculation(double, double, double);

SalaryInfo calculateBonus(double, int);
string helmetSize(int);
BinaryResult analyzeBinary(unsigned int);

void task10_1(const char*, const char*);
void task10_2(const char*);
void task10_3(const char*, const char*);

class ClassLab12_Kolesnyk {

public:
    ClassLab12_Kolesnyk(double length = 1.0);
    void setElength(double length = 1.0);
    double getElength();
    double getVolume();

private:
    double elength;
};

ClassLab12_Kolesnyk::ClassLab12_Kolesnyk(double length) {
    setElength(length);
}

void ClassLab12_Kolesnyk::setElength(double length) {
    if (length > 0.0)
        elength = length;
    else
        elength = 1.0;
}

double ClassLab12_Kolesnyk::getElength() {
    return elength;
}

double ClassLab12_Kolesnyk::getVolume() {
    return pow(elength, 3);
}

#endif // MODULESKOLESNYK_H_INCLUDED
