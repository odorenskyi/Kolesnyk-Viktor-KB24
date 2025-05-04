#ifndef STRUCT_TYPE_PROJECT_2_H_INCLUDED
#define STRUCT_TYPE_PROJECT_2_H_INCLUDED

#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isEmpty() const {
        return day == 0 && month == 0 && year == 0;
    }
    string toString() const {
        if (isEmpty()) return "-";
        return to_string(day) + "." + to_string(month) + "." + to_string(year);
    }
};

struct EmployeeRecord {
    Date date_filled;                          // ���� ����������
    int employee_id;                           // ��������� �����
    string tax_id;                             // ���������������� �����
    enum class Gender { M, F, Other } gender;  // �����
    string work_type;                          // ��� ������ (�������, �� �����������)
    string full_name;                          // ϲ� ����������
    Date birth_date;                           // ���� ����������
    string citizenship;                        // ������������
    string education;                          // �����
    string last_job;                           // ������ ���� ������
    string last_position;                      // ������� ������
    short int exp_days, exp_months, exp_years; // ���� ������ (���/������/����)
    string address;                            // ̳��� ����������
    string passport;                           // �������� ���
    string notes;                              // �������� �������
    Date dismissal_date;                       // ���� ���������
    string dismissal_reason;                   // ������� ���������
    EmployeeRecord() :
        employee_id(0),
        gender(Gender::Other),
        exp_days(0),
        exp_months(0),
        exp_years(0) {}
};

struct Node {
    EmployeeRecord record;
    Node* next;
    Node(EmployeeRecord rec) : record(rec), next(nullptr) {}
};

inline string genderToString(EmployeeRecord::Gender gender) { //��������� �������, ��� �� ������� �� ���� ������� ����� ������ ����
    switch (gender) {
        case EmployeeRecord::Gender::M: return "�������";
        case EmployeeRecord::Gender::F: return "Ƴ����";
        default: return "����";
    }
}

#endif // STRUCT_TYPE_PROJECT_2_H_INCLUDED
