#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

int add_employee(Employee **employees, int *count, int *capacity, Employee new_employee){
    //check if array is full then resize
    if(*count == *capacity){
        int new_capacity = *capacity * 2;
        
        Employee *temp_employees = realloc(*employees,(size_t)new_capacity * sizeof(**employees));
        if(temp_employees == NULL) {
            printf("Reallocation Failed!!\n");
            return 0;
        }
        //update oringinal pointer after successful realloc
        *employees = temp_employees;
        *capacity = new_capacity;
    }
    //insert new employee into array
    (*employees)[*count] = new_employee;
    //update number of stored employees
    (*count)++;
    //returns failure if employee was not added successfully
    return 1;
}

void update_employee(Employee *emp){
    int choice, c;

    printf("What do you want to update?\n");
    printf("1. Name\n2. Salary\n3. Date Hired\n");
    printf("Choice: ");
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid input! Please try again: ");
        //clear invalid input buffer
        while((c = getchar()) != '\n' && c != EOF);
    }
    //clear '\n' buffer
    while((c = getchar()) != '\n' && c != EOF);

    if(choice == 1) {
        printf("Enter new name: ");
        fgets(emp->name, sizeof(emp->name), stdin);
        emp->name[strcspn(emp->name, "\n")] = '\0';
        //copy the new name to the array
    } else if(choice == 2) {
        printf("Enter new salary: ");
        while(scanf("%f", &emp->salary) != 1) {
            printf("Invalid input. Please try again: ");
            while((c = getchar()) != '\n' && c != EOF);
        }
        while((c = getchar()) != '\n' && c != EOF);
    } else {
        printf("Enter new hire date:\n");
        printf("Day: ");
        while(scanf("%d", &emp->hired.day) != 1) {
            printf("Invalid input. Please try again: ");
            while((c = getchar()) != '\n' && c != EOF);
        }
        while((c = getchar()) != '\n' && c != EOF);
        printf("Month: ");
        while(scanf("%d", &emp->hired.month) != 1) {
            printf("Invalid input. Please try again: ");
            while((c = getchar()) != '\n' && c != EOF);
        }
        while((c = getchar()) != '\n' && c != EOF);
        printf("Year: ");
        while(scanf("%d", &emp->hired.year) != 1) {
            printf("Invalid input. Please try again: ");
            while((c = getchar()) != '\n' && c != EOF);
        }
        while((c = getchar()) != '\n' && c != EOF);
    }
}