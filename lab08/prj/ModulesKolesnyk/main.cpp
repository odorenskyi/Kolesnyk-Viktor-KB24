#include <iostream>
#include <cmath>

using namespace std;

double s_calculation(double x, double y, double z) {
    if (z < 0) {
        cout << "�������: �������� z �� ���� ���� ��'�����." << endl;
        return NAN;
    }
    double num = pow(x, 2) - pow(y, 3);
    double den = 12 * x + pow(y, 2) - M_PI * sqrt(z);

    if (den == 0) {
        cout << "�������: ��������� �� ���� ���� ��������." << endl;
        return NAN;
    }
    return num + sqrt(abs(z * exp(x)) / den);
}
