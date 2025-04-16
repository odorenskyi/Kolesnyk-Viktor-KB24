#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstring>
#include "ModulesKolesnyk.h"

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

SalaryInfo calculateBonus(double salary, int years) {
    SalaryInfo info;

    if (salary <= 0) {
        cout << "�������: �������� ������� ���� ����� ����" << endl;
        info.bonusPercent = 0;
        info.totalWithBonus = 0;
        return info;
    }
    if (years < 0) {
        cout << "�������: ���� ������ �� ���� ���� ��'�����" << endl;
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
        return "���������� �������� ������� ������";
}

BinaryResult analyzeBinary(unsigned int number) {
    BinaryResult result;

    if (number > 40008050 || number < 0) {
        cout << "�������: ����� ������� ���� � ����� �� 0 �� 40008050." << endl;
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

void task10_1(const char* inputFile, const char* outputFile) {
    // ������� ������� ���� ������������
    ifstream in(inputFile);
    ofstream out(outputFile);  // �������� ���� ��� ����������
    string word;
    in >> word;

    int vowelCount = 0;
    const char vowels[] = "��賿�����ŪȲ�����";
    for (size_t i = 0; i < word.length(); ++i) {
        for (size_t j = 0; j < sizeof(vowels) - 1; ++j) {
            if (word[i] == vowels[j]) {
                ++vowelCount;
                break;
            }
        }
    }

    const char* poem =
        "�� ����� �� ����� ������ �����. "
        "� ��� ���� - ���� �� ��� �� �����. "
        "��������� ������ ������ ����� ������ "
        "�������� ������� ��������� �����.";

    bool found = false;
    int poemLen = strlen(poem);
    int wlen = word.length();
    for (int i = 0; i <= poemLen - wlen; ++i) {
        int j = 0;
        while (j < wlen && poem[i + j] == word[j]) ++j;
        if (j == wlen && (i + j == poemLen || !isalpha(poem[i + j]))) {
            found = true;
            break;
        }
    }

    out << "���������: �������� ³����, ����, �������������, ������, 2025\n";
    out << "� ���� \"" << word << "\" �������� " << vowelCount << " �������� ����.\n";
    if (found) {
        out << "����� \"" << word << "\" ������� �� ���� ³���� ��������.\n";
    } else {
        out << "����� \"" << word << "\" ���� � ���� ³���� ��������.\n";
    }

    in.close();
    out.close();
}

void task10_2(const char* inputFile) {
    srand(time(NULL));

    ifstream in(inputFile);
    ofstream out(inputFile, ios::app);
    string word;
    in >> word;

    const char ukrUpperCase[] = "���å�Ū��Ȳ���������������������";

    for (size_t i = 0; i < word.length(); ++i) {
        for (size_t j = 0; j < strlen(ukrUpperCase); ++j) {
            if (word[i] == ukrUpperCase[j]) {
                word[i] = '0' + rand() % 10;
                break;
            }
        }
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    out << "������������ �����: " << word << "\n";
    out << "���� �� ��� ��������: " << dt << "\n";

    in.close();
    out.close();
}

void task10_3(const char* inputFile, const char* outputFile) {

    ifstream in(inputFile);
    ofstream out(outputFile);

    double x, y, z;
    int b;
    in >> x >> y >> z >> b;

    out << x << " " << y << " " << z << " " << b << "\n";

    double result = s_calculation(x, y, z);
    out << "��������� ���������� ������� s_calculation(" << x << ", " << y << ", " << z << ") ������� " << result << ".\n";

    char binary[65];
    int i = 0;
    int temp = b;
    if (temp == 0) {
        binary[i++] = '0';
    } else {
        while (temp > 0) {
            binary[i++] = (temp % 2) + '0';
            temp /= 2;
        }
    }
    binary[i] = '\0';
    for (int j = 0; j < i / 2; ++j) {
        char t = binary[j];
        binary[j] = binary[i - 1 - j];
        binary[i - 1 - j] = t;
    }

    out << "����� " << b << " � ������� ������: " << binary << ".\n";

    in.close();
    out.close();
}
