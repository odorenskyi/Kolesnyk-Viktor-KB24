#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include "ModulesKolesnyk.h"

using namespace std;

const int MAX_TESTS = 6;

struct TestCaseTask10_1 {
    char inputWord[50];
    char expectedOutput[200];
};

struct TestCaseTask10_2 {
    char inputWord[50];
    char expectedSubstring[50];
};

struct TestCaseTask10_3 {
    double x, y, z;
    int b;
    char expectedInput[50];
    char expectedOutput[300];
};


bool runTask10_1Test(const TestCaseTask10_1& testCase, const char* inputFile, const char* outputFile, ofstream& logFile) {
    ofstream inputFileWriter(inputFile);
    inputFileWriter << testCase.inputWord << endl;
    inputFileWriter.close();

    task10_1(inputFile, outputFile);

    ifstream outputFileReader(outputFile);
    string actualOutput;
    string line;
    while (getline(outputFileReader, line)) {
        actualOutput += line + "\n";
    }
    outputFileReader.close();

    bool passed = (actualOutput.find(testCase.expectedOutput) != string::npos);
    logFile << "Тест task10_1 - Вхід: \"" << testCase.inputWord << "\", Очікуваний фрагмент: " << testCase.expectedOutput << "Отриманий: " << actualOutput << "Статус: " << (passed ? "Passed" : "Failed") << "\n\n";

    return passed;
}

bool is_digit_char(char c) {
    return c >= '0' && c <= '9';
}

bool runTask10_2Test(const TestCaseTask10_2& testCase, const char* inputFile, ofstream& logFile) {
    ofstream inputFileWriter(inputFile);
    inputFileWriter << testCase.inputWord << endl;
    inputFileWriter.close();

    task10_2(inputFile);

    ifstream modifiedFileReader(inputFile);
    string originalWord;
    string modifiedLine;
    string timeString;

    if (!getline(modifiedFileReader, originalWord) ||
        !getline(modifiedFileReader, modifiedLine) ||
        !getline(modifiedFileReader, timeString)) {
        logFile << "Тест task10_2 - Вхід: \"" << testCase.inputWord << "\", Статус: Failed (не вдалося прочитати три рядки з файлу)\n";
        modifiedFileReader.close();
        return false;
    }
    modifiedFileReader.close();

    string modifiedWordFromLine = "";
    string prefix = "Модифіковане слово: ";

    if (modifiedLine.length() > prefix.length() && modifiedLine.substr(0, prefix.length()) == prefix) {
        modifiedWordFromLine = modifiedLine.substr(prefix.length());
    }

    bool lengthMatch = (originalWord.length() == modifiedWordFromLine.length());
    bool transformationCorrect = true;

    if (lengthMatch) {
        const char ukrUpperCase[] = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
        const char ukrLowerCase[] = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";

        for (size_t i = 0; i < originalWord.length(); ++i) {
            bool originalIsUpper = false;
            for (size_t j = 0; j < strlen(ukrUpperCase); ++j) {
                if (originalWord[i] == ukrUpperCase[j]) {
                    originalIsUpper = true;
                    break;
                }
            }
            if (originalIsUpper && !is_digit_char(modifiedWordFromLine[i])) {
                transformationCorrect = false;
                break;
            }
            bool originalIsLower = false;
            for (size_t j = 0; j < strlen(ukrLowerCase); ++j) {
                if (originalWord[i] == ukrLowerCase[j]) {
                    originalIsLower = true;
                    break;
                }
            }
            if (originalIsLower && originalWord[i] != modifiedWordFromLine[i]) {
                transformationCorrect = false;
                break;
            }
            if (!originalIsUpper && !originalIsLower && originalWord[i] != modifiedWordFromLine[i]) {
                transformationCorrect = false;
                break;
            }
        }
    } else {
        transformationCorrect = false;
    }

    string timePrefixUkr = "Дата та час дозапису: ";
    if (timeString.length() > timePrefixUkr.length() && timeString.substr(0, timePrefixUkr.length()) == timePrefixUkr) {
        timeString = timeString.substr(timePrefixUkr.length());
    }
    bool timeFormatValid = (timeString.length() > 20 && timeString.substr(0, 3) == "Wed" && timeString.find("2025") != string::npos);

    bool passed = lengthMatch && transformationCorrect && timeFormatValid;
    logFile << "Тест task10_2 - Вхід: \"" << testCase.inputWord << "\", Очікується: допис модифікованого слова та часу,\nОтримано (модиф. слово): \"" << modifiedWordFromLine << "\", (час): \"" << timeString << "\", \nСтатус: " << (passed ? "Passed" : "Failed") << "\n\n";

    return passed;
}

bool runTask10_3Test(const TestCaseTask10_3& testCase, const char* inputFile, const char* outputFile, ofstream& logFile) {
    ofstream inputFileWriter(inputFile);
    inputFileWriter << testCase.expectedInput << endl;
    inputFileWriter.close();

    task10_3(inputFile, outputFile);

    ifstream outputFileReader(outputFile);
    string actualOutput;
    string line;
    while (getline(outputFileReader, line)) {
        actualOutput += line + "\n";
    }
    outputFileReader.close();

    bool passed = (actualOutput.find(testCase.expectedOutput) != string::npos);
    logFile << "Тест task10_3 - Вхід (файл): \"" << testCase.expectedInput << "\", Очікуваний вивід: " << testCase.expectedOutput << "\Отриманий: " << actualOutput << "\Статус: " << (passed ? "Passed" : "Failed") << "\n\n";

    return passed;
}

int main() {
    char *locale = setlocale(LC_ALL, "");
    ofstream logFile("test_log.txt");

    TestCaseTask10_1 tests1[MAX_TESTS] = {
        {"щастя", "У слові \"щастя\" міститься 2 голосних літер.\nСлово \"щастя\" входить до вірша Віталія Іващенка.\n"},
        {"робота", "У слові \"робота\" міститься 3 голосних літер.\nСлова \"робота\" немає у вірші Віталія Іващенка.\n"},
        {"лінощів", "У слові \"лінощів\" міститься 3 голосних літер.\nСлово \"лінощів\" входить до вірша Віталія Іващенка.\n"},
        {"світло", "У слові \"світло\" міститься 2 голосних літер.\nСлова \"світло\" немає у вірші Віталія Іващенка.\n"},
        {"паляниця", "У слові \"паляниця\" міститься 4 голосних літер.\nСлова \"паляниця\" немає у вірші Віталія Іващенка.\n"},
        {"яр", "У слові \"яр\" міститься 1 голосних літер.\nСлова \"яр\" немає у вірші Віталія Іващенка.\n"},
    };
    const char* inputFile1 = "input_task10_1.txt";
    const char* outputFile1 = "output_task10_1.txt";
    logFile << "--- Тестування task10_1 ---\n";
    for (int i = 0; i < MAX_TESTS && strlen(tests1[i].inputWord) > 0; ++i) {
        runTask10_1Test(tests1[i], inputFile1, outputFile1, logFile);
    }
    logFile << "\n";

    TestCaseTask10_2 tests2[MAX_TESTS] = {
        {"ЩАСТЯ"},
        {"Світло"},
        {"паляниця"},
        {"ПаляницЯ"},
        {"ІВАЩЕНКО"},
        {"ДопомоЖІТЬ"}
    };
    const char* inputFile2 = "input_task10_2.txt";
    logFile << "--- Тестування task10_2 ---\n";
    for (int i = 0; i < MAX_TESTS && strlen(tests2[i].inputWord) > 0; ++i) {
        runTask10_2Test(tests2[i], inputFile2, logFile);
    }
    logFile << "\n";

    TestCaseTask10_3 tests3[MAX_TESTS] = {
        {1.0, 2.0, 3.0, 6, "1 2 3 6", "1 2 3 6\nРезультат обчислення функції s_calculation(1, 2, 3) дорівнює -6.12117.\nЧисло 6 у двійковій системі: 110.\n"},
        {2.0, 2.0, 4.0, 6, "2 2 4 6", "2 2 4 6\nРезультат обчислення функції s_calculation(2, 2, 4) дорівнює -2.83339.\nЧисло 6 у двійковій системі: 110.\n"},
        {15.0, 11.0, 9.0, 6, "15 11 9 6", "15 11 9 6\nРезультат обчислення функції s_calculation(15, 11, 9) дорівнює -788.346.\nЧисло 6 у двійковій системі: 110.\n"},
        {36.0, 5.0, 4.0, 6, "36 5 4 6", "36 5 4 6\nРезультат обчислення функції s_calculation(36, 5, 4) дорівнює 6.18673e+06.\nЧисло 6 у двійковій системі: 110.\n"},
        {100.0, -100.0, 50.0, 6, "100 -100 50 6", "100 -100 50 6\nРезультат обчислення функції s_calculation(100, -100, 50) дорівнює 3.46762e+20.\nЧисло 6 у двійковій системі: 110.\n"},
        {55.0, 15.0, 22.0, 13, "55 15 22 13", "55 15 22 13\nРезультат обчислення функції s_calculation(55, 15, 22) дорівнює 1.39471e+11.\nЧисло 13 у двійковій системі: 1101.\n"},
    };
    const char* inputFile3 = "input_task10_3.txt";
    const char* outputFile3 = "output_task10_3.txt";
    logFile << "--- Тестування task10_3 ---\n";
    for (int i = 0; i < MAX_TESTS && tests3[i].expectedOutput[0] != '\0'; ++i) {
        runTask10_3Test(tests3[i], inputFile3, outputFile3, logFile);
    }
    logFile << "\n";
    logFile.close();

    return 0;
}
