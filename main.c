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
    int choice;

    do {
        choice = menu();
        switch(choice){
            case 1:
                // call add_employee(...)
           break;

       case 2:
           // call remove_employee(...)
           break;

       case 3:
           // call give_raise(...)
           break;

       case 4:
           // call oldest_employee(...)
           break;

       case 5:
           // call print_all(...)
           break;
   }

} while(choice != 6);
    return 0;
}

int menu() {
    int choice;
    printf("WELCOME TO THE EMPLOYEE MANAGER, SELECT AN OPTION\n");
    printf("1. Add Employee\n2. Remove Employee\n3. Give Raise\n4. Find Oldest Employee\n5. Print All Employees\n6. Exit\n");
    scanf("%d", &choice);
    return choice;
}

