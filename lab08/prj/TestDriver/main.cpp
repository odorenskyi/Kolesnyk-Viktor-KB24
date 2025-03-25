#include <iostream>
#include <cmath>
#include <locale>
#include "ModulesKolesnyk.h"

using namespace std;

struct TestCase {
    double x;
    double y;
    double z;
    double expected;
    bool isExpectedError;
};

bool compare(double result, double expected, bool isExpectedError) {
    if (isExpectedError) {
        return isnan(result);
    }
    return abs(result - expected) < 1e-2;
}

void runTests() {
    TestCase testCases[] = {
        {0, 0, 0, NAN, true},
        {1.0, 1.0, 1.0, 0.52, false},
        {-1.0, -1.0, -1.0, NAN, true},
        {2.0, 2.0, 2.0, -3.2, false},
        {-2.0, -2.0, -2.0, NAN, true},
        {3.0, 3.0, 3.0, -16.76, false},
        {-3.0, -3.0, -3.0, NAN, true},
        {10.0, 5.0, 2.0, -7.29, false},
        {-10.0, -5.0, -2.0, NAN, true},
        {8.5, 1.0, 2.1, 81.48, false},
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    int passedTests = 0;

    for (int i = 0; i < numTests; ++i) {
        cout << "Тест " << i + 1 << ": x = " << testCases[i].x << ", y = " << testCases[i].y << ", z = " << testCases[i].z << endl;
        double result = s_calculation(testCases[i].x, testCases[i].y, testCases[i].z);
        if (compare(result, testCases[i].expected, testCases[i].isExpectedError)) {
            cout << "Статус: Passed" << endl;
            passedTests++;
        } else {
            cout << "Статус: Failed" << endl;
            cout << "Отриманий результат: " << result << ", очікуваний: " << testCases[i].expected << endl;
        }
        cout << "-----------------------------" << endl;
    }

    cout << "Тестування завершено: " << passedTests << " з " << numTests << " тестів пройшли успішно." << endl;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    runTests();
    return 0;
}
