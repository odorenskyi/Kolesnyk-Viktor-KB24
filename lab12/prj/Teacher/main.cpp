#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "ModulesKolesnyk.h"

using namespace std;

const int MAX_TESTS = 7;

struct TestCase {
    double input = 0.0;
    bool hasInput = false;
    double expectedLength = 0.0;
    bool hasExpectedLength = false;
    double expectedVolume = 0.0;
    bool hasExpectedVolume = false;
};

void beep(int n) {
    for (int i = 0; i < n; ++i)
        cout << '\a';
}

bool isValidPath() {
    ifstream testFile("..\\prj\\Teacher\\main.cpp");
    return testFile.is_open();
}

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    if (start == string::npos || end == string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

int main(int argc, char* argv[]) {
    beep(100);

    if (!isValidPath()) {
        ofstream error("..\\TestSuite\\TestResults.txt");
        error << "Встановлені вимоги порядку виконання лабораторної роботи порушено!\n";
        error.close();
        return 1;
    }

    TestCase tests[MAX_TESTS];
    int testCount = 0;

    ifstream in("..\\TestSuite\\TestCases_Kolesnyk.txt");
    if (!in) {
        cerr << "Не вдалося відкрити файл тест-кейсів.\n";
        return 1;
    }

    string line;
    TestCase current = {};
    bool firstTestCase = true;

    while (getline(in, line)) {
        line = trim(line);
        if (line.empty()) continue;

        if (line.find("# Тест-кейс") == 0) {
            if (!firstTestCase) {
                if (current.hasInput || current.hasExpectedLength || current.hasExpectedVolume) {
                    tests[testCount++] = current;
                    cout << "Додано тест №" << testCount << "\n";
                    if (testCount >= MAX_TESTS) break;
                }
            }
            current = {};
            firstTestCase = false;
        }
        else if (line.find("INPUT:") == 0) {
            current.input = stod(line.substr(6));
            current.hasInput = true;
        }
        else if (line.find("EXPECTED_LENGTH:") == 0) {
            current.expectedLength = stod(line.substr(16));
            current.hasExpectedLength = true;
        }
        else if (line.find("EXPECTED_VOLUME:") == 0) {
            current.expectedVolume = stod(line.substr(16));
            current.hasExpectedVolume = true;
        }
    }
    if (current.hasInput || current.hasExpectedLength || current.hasExpectedVolume) {
        tests[testCount++] = current;
        cout << "Додано тест №" << testCount << "\n";
    }
    in.close();

    ofstream out("..\\TestSuite\\TestResults.txt");
    if (!out) {
        cerr << "Не вдалося створити файл для результатів.\n";
        return 1;
    }

    for (int i = 0; i < testCount; ++i) {
        out << "Тест-кейс №" << (i + 1) << ": ";
        TestCase& t = tests[i];
        ClassLab12_Kolesnyk cub(t.input);

        bool success = true;

        if (t.hasExpectedLength) {
            double got = cub.getElength();
            if (abs(got - t.expectedLength) > 0.0001) {
                out << "ПОМИЛКА (Length: очікувалося " << t.expectedLength << ", отримано " << got << ") ";
                success = false;
            }
        }

        if (t.hasExpectedVolume) {
            double got = cub.getVolume();
            if (abs(got - t.expectedVolume) > 0.0001) {
                out << "ПОМИЛКА (Volume: очікувалося " << t.expectedVolume << ", отримано " << got << ") ";
                success = false;
            }
        }

        if (success) out << "успішно";
        out << "\n";
    }
    out.close();

    return 0;
}
