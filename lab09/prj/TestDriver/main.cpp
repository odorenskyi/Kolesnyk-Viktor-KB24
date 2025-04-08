#include <iostream>
#include <string>
#include <cmath>
#include <locale>
#include "ModulesKolesnyk.h"

using namespace std;

struct BonusTestCase {
    double salary;
    int years;
    double expectedBonusPercent;
    double expectedTotalWithBonus;
    bool isExpectedError;
    string errorMessage;
};

bool compareBonus(SalaryInfo result, double expectedBonusPercent, double expectedTotalWithBonus) {
    return abs(result.bonusPercent - expectedBonusPercent) == 0 && abs(result.totalWithBonus - expectedTotalWithBonus) == 0;
}

void runBonusTests() {
    BonusTestCase bonusTestCases[] = {
        {10000, 1, 0, 10000, false, ""},
        {15000, 2, 5, 15750, false, ""},
        {12000, 5, 10, 13200, false, ""},
        {20000, 10, 25, 25000, false, ""},
        {8000, 7, 10, 8800, false, ""},
        {0, 3, 0, 0, true, "�������: �������� ������� ���� ����� ����"},
        {-5000, 4, 0, 0, true, "�������: �������� ������� ���� ����� ����"},
        {11000, -2, 0, 0, true, "�������: ���� ������ �� ���� ���� ��'�����"},
        {10000, 11, 25, 12500, false, ""},
        {5000, 0, 0, 5000, false, ""}
    };

    int numTests = sizeof(bonusTestCases) / sizeof(bonusTestCases[0]);
    int passedTests = 0;

    cout << "\n���������� ������� calculateBonus:" << endl;
    for (int i = 0; i < numTests; ++i) {
        cout << "���� " << i + 1 << ": salary = " << bonusTestCases[i].salary << ", years = " << bonusTestCases[i].years << endl;
        SalaryInfo result = calculateBonus(bonusTestCases[i].salary, bonusTestCases[i].years);
        cout << "��������� �����: " << result.bonusPercent << "%, ������: " << result.totalWithBonus << endl;
        if (!bonusTestCases[i].isExpectedError) {
            if (compareBonus(result, bonusTestCases[i].expectedBonusPercent, bonusTestCases[i].expectedTotalWithBonus)) {
                cout << "������: Passed" << endl;
                passedTests++;
            } else {
                cout << "������: Failed" << endl;
                cout << "���������� �����: " << bonusTestCases[i].expectedBonusPercent << "%, ������: " << bonusTestCases[i].expectedTotalWithBonus << endl;
            }
        } else {
            cout << "������: �������� ��������� �������: \"" << bonusTestCases[i].errorMessage << "\"" << endl;
            passedTests++;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "���������� ���������: " << passedTests << " � " << numTests << " ����� ������� ������." << endl;
}

struct HelmetTestCase {
    int head;
    string expected;
};

bool compareHelmet(string result, string expected) {
    return result == expected;
}

void runHelmetTests() {
    HelmetTestCase helmetTestCases[] = {
        {53, "XS"},
        {54, "XS"},
        {55, "S"},
        {58, "M"},
        {59, "L"},
        {62, "XL"},
        {52, "���������� �������� ������� ������"},
        {40008050, "���������� �������� ������� ������"},
        {-1, "���������� �������� ������� ������"},
        {60, "L"}
    };

    int numTests = sizeof(helmetTestCases) / sizeof(helmetTestCases[0]);
    int passedTests = 0;

    cout << "\n���������� ������� helmetSize:" << endl;
    for (int i = 0; i < numTests; ++i) {
        cout << "���� " << i + 1 << ": head = " << helmetTestCases[i].head << endl;
        string result = helmetSize(helmetTestCases[i].head);
        cout << "��������� �����: " << result << endl;
        if (compareHelmet(result, helmetTestCases[i].expected)) {
            cout << "������: Passed" << endl;
            passedTests++;
        } else {
            cout << "������: Failed" << endl;
            cout << "���������� �����: " << helmetTestCases[i].expected << endl;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "���������� ���������: " << passedTests << " � " << numTests << " ����� ������� ������." << endl;
}

struct BinaryTestCase {
    unsigned int number;
    bool expectedBit16Value;
    int expectedCountMatching;
    bool isExpectedError;
    string errorMessage;
};

bool compareBinary(BinaryResult result, bool expectedBit16Value, int expectedCountMatching) {
    return result.bit16Value == expectedBit16Value && result.countMatching == expectedCountMatching;
}

void runBinaryTests() {
    BinaryTestCase binaryTestCases[] = {
        {0, false, 0, false, ""},
        {1, false, 1, false, ""},
        {2, false, 1, false, ""},
        {32768, true, 31, false, ""},
        {65535, true, 16, false, ""},
        {40008050, false, 13, false, ""},
        {static_cast<unsigned int>(-1), false, -1, true, "�������: ����� ������� ���� � ����� �� 0 �� 40008050."},
        {40008051, false, -1, true, "�������: ����� ������� ���� � ����� �� 0 �� 40008050."},
        {10000, false, 5, false, ""},
        {1000000, false, 7, false, ""}
    };

    int numTests = sizeof(binaryTestCases) / sizeof(binaryTestCases[0]);
    int passedTests = 0;

    cout << "\n���������� ������� analyzeBinary:" << endl;
    for (int i = 0; i < numTests; ++i) {
        cout << "���� " << i + 1 << ": number = " << binaryTestCases[i].number << endl;
        BinaryResult result = analyzeBinary(binaryTestCases[i].number);
        cout << "��������: bit16Value = " << result.bit16Value << ", countMatching = " << result.countMatching << endl;
        if (!binaryTestCases[i].isExpectedError) {
            if (compareBinary(result, binaryTestCases[i].expectedBit16Value, binaryTestCases[i].expectedCountMatching)) {
                cout << "������: Passed" << endl;
                passedTests++;
            } else {
                cout << "������: Failed" << endl;
                cout << "���������: bit16Value = " << binaryTestCases[i].expectedBit16Value << ", countMatching = " << binaryTestCases[i].expectedCountMatching << endl;
            }
        } else {
            cout << "������: �������� ��������� �������: \"" << binaryTestCases[i].errorMessage << "\"" << endl;
            passedTests++;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "���������� ���������: " << passedTests << " � " << numTests << " ����� ������� ������." << endl;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    runBonusTests();
    runHelmetTests();
    runBinaryTests();
    return 0;
}
