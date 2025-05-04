#ifndef MODULE_SEARCHDEL_KOLESNYK_H
#define MODULE_SEARCHDEL_KOLESNYK_H

#include "struct_type_project_2.h"
#include <string>

using namespace std;

bool findRecordByName(Node*, const string&);
bool deleteRecord(Node*&, int);

#endif // MODULE_SEARCHDEL_KOLESNYK_H
