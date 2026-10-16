#ifndef STORAGE_H
#define STORAGE_H

#include "employee.h"

int load_employees(Employee **employees, int *count, int *capacity);
int save_employees(const Employee *employees, int count);

#endif