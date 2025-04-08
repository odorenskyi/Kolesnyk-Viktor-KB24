#include <iostream>
#include <cmath>
#include "ModulesKolesnyk.h"

using namespace std;

void task_r() {
    double salary;
    int years;
    cout << "Введiть зарплату: ";
    cin >> salary;
    cout << "Введіть стаж (рокiв): ";
    cin >> years;
    SalaryInfo info = calculateBonus(salary, years);
    cout << "Надбавка: " << info.bonusPercent << "%\n";
    cout << "Загальна сума з надбавкою: " << info.totalWithBonus << " грн\n";
}

void task_f() {
    int head;
    cout << "Введiть обхват голови в см: ";
    cin >> head;
    cout << "Розмiр шолома: " << helmetSize(head) << endl;
}

void task_t() {
    unsigned int number;
    cout << "Введіть число: ";
    cin >> number;
    BinaryResult res = analyzeBinary(number);
    if (res.countMatching != -1) {
        cout << "Значення бiта №16: " << res.bit16Value << endl;
        cout << "Кiлькiсть бiтiв " << !res.bit16Value << " дорiвнює " << res.countMatching << endl;
    }
}

void task_e() {
    double x, y, z;
    cout << "Введiть значення x, y, z: ";
    cin >> x >> y >> z;
    double s = s_calculation(x, y, z);
    if (!isnan(s)) {
        cout << "Результат обчислення s = " << s << endl;
    }
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    char command;
    cout << "Iнтерактивна система. Введiть команду:\n"
         << "r - розрахунок надбавки до зарплати\n"
         << "f - визначення розмiру шолома\n"
         << "t - обробка бiтiв числа\n"
         << "e - обчислення формули\n"
         << "g, G, o - завершити\n";

    while (true) {
        cout << "\nВведiть команду: ";
        cin >> command;
        switch (command) {
            case 'r': task_r(); break;
            case 'f': task_f(); break;
            case 't': task_t(); break;
            case 'e': task_e(); break;
            case 'g':
            case 'G':
            case 'o':
                cout << "Завершення роботи...\n";
                return 0;
            default:
                cout << "\aНевiдома команда!\n";
        }
    }
}
