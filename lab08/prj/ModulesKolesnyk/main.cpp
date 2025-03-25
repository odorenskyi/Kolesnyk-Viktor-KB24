#include <cmath>

double s_calculation(double x, double y, double z) {
    double num = pow(x, 2) - pow(y, 3);
    double den = 12 * x + pow(y, 2) - M_PI * sqrt(z);

    if (den == 0 || z < 0) {
        return NAN;
    }
    return num + sqrt(abs(z * exp(x)) / den);
}
