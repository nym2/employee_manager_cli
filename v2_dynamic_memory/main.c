#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day, month, year
} Date;

typedef struct {
    int ID;
    char name[50];
    float salary;
    Date hired;
} Employee;