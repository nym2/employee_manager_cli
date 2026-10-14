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

#endif