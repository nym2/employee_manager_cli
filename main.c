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

int menu();

int main(void) {
    Employee employees[100];
    int count = 0;
    return 0;
}

int menu() {
    int choice;
    printf("WELCOME TO THE EMPLOYEE MANAGER, SELECT AN OPTION\n");
    printf("0. Add Employee\n1. Remove Employee\n2. Give Raise\n3. Find Oldest Employee\n4. Print All Employees\n5. Exit\n");
    scanf("%d", &choice);
    return choice;
}