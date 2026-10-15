#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int id;
    char name[50];
    float salary;
    Date hired;
} Employee;

int add_employee(Employee **employees, int *count, int *capacity, Employee new_employee);
void update_employee(Employee *emp);
int remove_employee(Employee *employees, int *count, int id);

#endif