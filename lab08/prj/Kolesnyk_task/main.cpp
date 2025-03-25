#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <locale>
#include "ModulesKolesnyk.h"

using namespace std;


string developerInfo() {
    return "(©) Розробник: Колесник Віктор. Усі права захищені. \n";
}

int expression(char a, char b) {
    return (a <= b - 32) ? 1 : 0;
}

string values(double x, double y, double z) {
    stringstream ss; //створення потоку, щоб можна було все
    ss << "x (dec) = " << x << ", x (hex) = " << uppercase << hex << static_cast<int>(x) << dec << "\n";
    ss << "y (dec) = " << y << ", y (hex) = " << uppercase << hex << static_cast<int>(y) << dec << "\n";
    ss << "z (dec) = " << z << ", z (hex) = " << uppercase << hex << static_cast<int>(z) << dec << "\n";
    return ss.str();  // Повертаємо форматований рядок
}

double calculateS(double x, double y, double z) {
    double S = s_calculation(x, y, z);
    return S;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    double x, y, z;
    char a, b;
    cout << "Введіть x, y, z: ";
    cin >> x >> y >> z;
    cout << "Введіть два символи a та b: ";
    cin >> a >> b;
    cout << developerInfo();
    cout << "Результат логічного виразу (1/0): " << expression(a, b) << "\n";
    cout << values(x, y, z);
    cout << fixed << setprecision(5) << "S = " << calculateS(x, y, z) << "\n";
    return 0;
}
