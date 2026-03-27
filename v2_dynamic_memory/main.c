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


int menu(void);


int main(void) {
    int choice;
    //keeps track of how many employees are currently in the array
    int count = 0;
    //initalised capacity so as to implement dynamic growth
    int capacity = 4;
    Employee *employees = calloc(capacity, sizeof(*employees));
    if(employees == NULL) {
        printf("memory allocation failed!!\n");
        return 1;
    }

    while(1) {
        choice = menu();
        switch(choice) {
            case 1: {
                //add_employees
            }

            case 8: {
                printf("Exiting program...\n");
                free(employees);
                return 0;
            }
            
            default: {
                printf("Invalid choice\n");
            }
        }
    }



    return 0;
}


// Displays menu and returns validated user choice
int menu(void) {
    int choice;
    int c;

    printf("\n===== Employee Manager =====\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Search Employee\n");
    printf("4. Update Employee\n");
    printf("5. Give Raise\n");
    printf("6. Remove Employee\n");
    printf("7. Oldest Employee\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");

    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 8) {
        printf("invalid input. Please try again: ");
        //clear buffer
        while((c = getchar())  != '\n' && c != EOF);
    }
    //clear the '\n' after the input is valid
    while((c = getchar()) != '\n' && c != EOF);

    return choice;
}

