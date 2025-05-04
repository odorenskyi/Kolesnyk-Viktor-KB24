#include <iostream>
#include <string>
#include <cstdlib>
#include "struct_type_project_2.h"
#include "Module_File_Zaritskyi.h"
#include "Module_CRUD_Kondratenko.h"
#include "Module_SearchDel_Kolesnyk.h"

using namespace std;

static Node* g_head = nullptr;
static const char* DATABASE_FILE = "database.bin";

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseExecution() {
    cout << "\nНатисніть Enter для продовження...";
    cin.ignore(32767, '\n');
}

void actionShowAll() {
    clearScreen();
    cout << "=== Всі записи ===\n";
    printAllRecords(g_head);
}

void actionSaveToFile() {
    clearScreen();
    cout << "=== Збереження у файл ===\n";
    string fname;
    cout << "Введіть ім'я файлу (default output.txt): ";
    getline(cin, fname);
    if (fname.empty()) fname = "output.txt";
    printAllRecords(g_head, true, fname);
}

void actionAddNew() {
    clearScreen();
    addRecord(g_head);
}

void actionSearch() {
    clearScreen();
    cout << "=== Пошук за прізвищем ===\n";
    string query;
    cout << "Введіть прізвище або частину ПІБ: ";
    getline(cin, query);
    if (!query.empty())
        findRecordByName(g_head, query);
    else
        cout << "Порожній запит!\n";
}

void actionDelete() {
    clearScreen();
    cout << "=== Видалення запису ===\n";
    cout << "Введіть табельний номер: ";
    string line;
    getline(cin, line);
    int id = 0;
    try {
        id = stoi(line);
        deleteRecord(g_head, id);
    } catch (...) {
        cout << "Некоректний номер!\n";
    }
}

typedef void (*MenuAction)();

int main() {
    g_head = nullptr;
    loadDatabase(g_head, DATABASE_FILE);
    const char* menuText[] = {
        "Переглянути всю базу",
        "Зберегти базу у текстовий файл",
        "Додати новий запис",
        "Пошук за прізвищем",
        "Видалити запис за табельним номером"
    };
    MenuAction actions[] = {
        actionShowAll,
        actionSaveToFile,
        actionAddNew,
        actionSearch,
        actionDelete
    };

    const int MENU_SIZE = sizeof(menuText) / sizeof(menuText[0]);
    bool running = true;

    while (running) {
        clearScreen();
        cout << "=== Відділ кадрів: Особова картка ===\n\n";
        for (int i = 0; i < MENU_SIZE; ++i) {
            cout << (i + 1) << ". " << menuText[i] << "\n";
        }
        cout << "0. Вихід\n\nВаш вибір: ";

        string choice;
        getline(cin, choice);

        int opt = -1;
        try {
            opt = stoi(choice);
        } catch (...) {
            opt = -1;
        }

        if (opt == 0) {
            clearScreen();
            cout << "Збереження та вихід...\n";
            saveDatabase(g_head, DATABASE_FILE);
            running = false;
        }
        else if (opt >= 1 && opt <= MENU_SIZE) {
            actions[opt - 1]();
            pauseExecution();
        }
        else {
            cout << "Невідома опція!\n";
            pauseExecution();
        }
    }
    while (g_head) {
        Node* tmp = g_head;
        g_head = g_head->next;
        delete tmp;
    }
    return 0;
}
