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