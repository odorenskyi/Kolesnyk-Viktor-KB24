#include <iostream>
#include <cmath>
#include "ModulesKolesnyk.h"

using namespace std;

void task_r() {
    double salary;
    int years;
    cout << "����i�� ��������: ";
    cin >> salary;
    cout << "������ ���� (���i�): ";
    cin >> years;
    SalaryInfo info = calculateBonus(salary, years);
    cout << "��������: " << info.bonusPercent << "%\n";
    cout << "�������� ���� � ���������: " << info.totalWithBonus << " ���\n";
}

void task_f() {
    int head;
    cout << "����i�� ������ ������ � ��: ";
    cin >> head;
    cout << "����i� ������: " << helmetSize(head) << endl;
}

void task_t() {
    unsigned int number;
    cout << "������ �����: ";
    cin >> number;
    BinaryResult res = analyzeBinary(number);
    if (res.countMatching != -1) {
        cout << "�������� �i�� �16: " << res.bit16Value << endl;
        cout << "�i���i��� �i�i� " << !res.bit16Value << " ���i���� " << res.countMatching << endl;
    }
}

void task_e() {
    double x, y, z;
    cout << "����i�� �������� x, y, z: ";
    cin >> x >> y >> z;
    double s = s_calculation(x, y, z);
    if (!isnan(s)) {
        cout << "��������� ���������� s = " << s << endl;
    }
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    char command;
    cout << "I����������� �������. ����i�� �������:\n"
         << "r - ���������� �������� �� ��������\n"
         << "f - ���������� ����i�� ������\n"
         << "t - ������� �i�i� �����\n"
         << "e - ���������� �������\n"
         << "g, G, o - ���������\n";

    while (true) {
        cout << "\n����i�� �������: ";
        cin >> command;
        switch (command) {
            case 'r': task_r(); break;
            case 'f': task_f(); break;
            case 't': task_t(); break;
            case 'e': task_e(); break;
            case 'g':
            case 'G':
            case 'o':
                cout << "���������� ������...\n";
                return 0;
            default:
                cout << "\a���i���� �������!\n";
        }
    }
}
