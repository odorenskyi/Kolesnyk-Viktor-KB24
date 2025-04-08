#ifndef MODULESKOLESNYK_H_INCLUDED
#define MODULESKOLESNYK_H_INCLUDED
#include <string>

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

#endif // MODULESKOLESNYK_H_INCLUDED
