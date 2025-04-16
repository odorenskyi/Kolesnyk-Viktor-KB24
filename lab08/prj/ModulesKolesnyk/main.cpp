#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstring>
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

void task10_1(const char* inputFile, const char* outputFile) {
    // Заміщаємо вхідний файл результатами
    ifstream in(inputFile);
    ofstream out(outputFile);  // Вихідний файл для результатів
    string word;
    in >> word;

    int vowelCount = 0;
    const char vowels[] = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    for (size_t i = 0; i < word.length(); ++i) {
        for (size_t j = 0; j < sizeof(vowels) - 1; ++j) {
            if (word[i] == vowels[j]) {
                ++vowelCount;
                break;
            }
        }
    }

    const char* poem =
        "До щастя не пускає лінощів орава. "
        "У чім воно - ніхто не знає до пуття. "
        "Навчитись радісно робити кожну справу "
        "Найперше правило щасливого життя.";

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

    out << "Розробник: Колесник Віктор, ЦНТУ, Кропивницький, Україна, 2025\n";
    out << "У слові \"" << word << "\" міститься " << vowelCount << " голосних літер.\n";
    if (found) {
        out << "Слово \"" << word << "\" входить до вірша Віталія Іващенка.\n";
    } else {
        out << "Слова \"" << word << "\" немає у вірші Віталія Іващенка.\n";
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

    const char ukrUpperCase[] = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

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

    out << "Модифіковане слово: " << word << "\n";
    out << "Дата та час дозапису: " << dt << "\n";

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
    out << "Результат обчислення функції s_calculation(" << x << ", " << y << ", " << z << ") дорівнює " << result << ".\n";

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

    out << "Число " << b << " у двійковій системі: " << binary << ".\n";

    in.close();
    out.close();
}
