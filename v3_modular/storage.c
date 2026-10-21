
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

#define EMPLOYEE_FILE "data/employees.txt"

int load_employees(Employee **employees, int *count, int *capacity)
{
    FILE *file = fopen(EMPLOYEE_FILE, "r");

    if (file == NULL)
    {
        perror("Could not open employee file");
        return 0;
    }

    /* We will read employee records here. */

    fclose(file);
    return 1;
}

int save_employees(const Employee *employees, int count)
{
    /* We will implement saving later. */
    (void)employees;
    (void)count;
    return 0;
}
