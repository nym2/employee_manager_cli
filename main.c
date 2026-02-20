#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[30];
    float salary;
    Date hired;
} Employee;

int main(void) {
    Employee employees[100];
    int count = 0;
    return 0;
}
