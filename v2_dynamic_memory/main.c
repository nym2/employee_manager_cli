#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int day, month, year;
} Date;

typedef struct {
    int id;
    char name[50];
    float salary;
    Date hired;
} Employee;


int menu(void);
Employee **add_employee(Employee **employees, int *count, int *capacity, Employee new_employee);
void print_employees(const Employee *employees, int count);
Employee *search_employee(Employee *employees, int count, int id);
void update_employee(Employee *emp);
int give_raise(Employee *emp, float percent_raise);
int remove_employee(Employee *employees, int *count, int id);


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
                Employee new_emp;
                int c;

                printf("Enter ID: ");
                while(scanf("%d", &new_emp.id) != 1) {
                    printf("Invalid input. Please try again: ");
                    //clear buffer from invalid input
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clear '\n' buffer after a valid input
                while((c = getchar()) != '\n' && c != EOF);

                printf("Enter Name: ");
                fgets(new_emp.name, sizeof(new_emp.name), stdin);
                new_emp.name[strcspn(new_emp.name, "\n")] = '\0';

                printf("Enter Salary: ");
                while(scanf("%f", &new_emp.salary) != 1) {
                    printf("Invalid input. Please try again");
                    //clear buffer from invalid input
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clear '\n' buffer after a valid input
                while((c = getchar()) != '\n' && c != EOF);
                
                printf("Enter Date Hired\n");
                printf("Day: ");
                while(scanf("%d", &new_emp.hired.day) != 1) {
                    printf("Invalid input. please try again: ");
                    //clear buffer from invalid input
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clear '\n' buffer after a valid input
                while((c = getchar()) != '\n' && c != EOF);

                printf("Month: ");
                while(scanf("%d", &new_emp.hired.month) != 1) {
                    printf("Invalid input. please try again: ");
                    //clear buffer from invalid input
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clear '\n' buffer after a valid input
                while((c = getchar()) != '\n' && c != EOF);

                printf("Year: ");
                while(scanf("%d", &new_emp.hired.year) != 1) {
                    printf("Invalid input. please try again: ");
                    //clear buffer from invalid input
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clear '\n' buffer after a valid input
                while((c = getchar()) != '\n' && c != EOF);

                Employee **added = add_employee(&employees, &count, &capacity, new_emp);
                    if(added == NULL) {
                        printf("Failed to add employee!!\n");
                    }
                break;
            }

            case 2: {
                print_employees(employees, count);
                break;
            }

            case 3: {
                int id, c;
                printf("ID: ");
                while(scanf("%d", &id) != 1 || id < 0){
                    printf("invalid input! Please try again: ");
                    //clears invalid input buffer
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clears '\n' buffer
                while((c = getchar()) != '\n' && c != EOF);
                Employee *found = search_employee(employees, count, id);
                if(found == NULL) {
                    printf("Employee not found\n");
                } else {
                    printf("\nEmployee Found:\n");
                    printf("ID: %d\n", found->id);
                    printf("Name: %s\n", found->name);
                    printf("Salary: %.2f\n", found->salary);
                    printf("Hired: %02d-%02d-%d\n",
                        found->hired.day,
                        found->hired.month,
                        found->hired.year);
                }

                break;

            }

            case 4: {
                int id, c;
                printf("Enter Employee ID: ");
                while(scanf("%d", &id) != 1 || id < 0){
                    printf("invalid input! Please try again: ");
                    //clears invalid input buffer
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clears '\n' buffer
                while((c = getchar()) != '\n' && c != EOF);
                Employee *found = search_employee(employees, count, id);
                if(found != NULL) {
                    update_employee(found);
                    printf("Employee updated successfully.\n");
                } else {
                    printf("Employee not found!!\n");
                }

                break;

            }

            case 5: {
                int id, c;
                float percent;
                printf("Enter Employee ID: ");
                while(scanf("%d", &id) != 1 || id < 0){
                    printf("invalid input! Please try again: ");
                    //clears invalid input buffer
                    while((c = getchar()) != '\n' && c != EOF);
                }
                //clears '\n' buffer
                while((c = getchar()) != '\n' && c != EOF);
                Employee *found = search_employee(employees, count, id);
                if(found != NULL) {
                    printf("Enter the percentage raise: ");
                    while(scanf("%f", &percent) != 1 || percent < 0) {
                        printf("Invalid input. Please try again: ");
                        while((c = getchar()) != '\n' && c != EOF);
                    }
                    while((c = getchar()) != '\n' && c != EOF);
                    give_raise(found, percent);
                    printf("Salary updated successfully.\n");
                    printf("New Salary: %.2f\n", found->salary);
                } else {
                    printf("Employee not found!!\n");
                }

                break;
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

Employee **add_employee(Employee **employees, int *count, int *capacity, Employee new_employee){
    //check if array is full then resize
    if(*count == *capacity){
        *capacity *= 2;
        Employee *temp_employees = realloc((*employees), (*capacity) * sizeof(**employees));
        if(temp_employees == NULL) {
            printf("Reallocation Failed!!\n");
            return NULL;
        }
        //update oringinal pointer after successful realloc
        *employees = temp_employees;
    }
    //insert new employee into array
    (*employees)[*count] = new_employee;
    //update number of stored employees
    (*count)++;
    //return a pointer to the newly added employee(useful for further operations)
    return &employees[*count - 1];
}

void print_employees(const Employee *employees, int count) {
    //implemented defensive programming to handle empty array
    if(count == 0) {
        printf("No employees to display.\n");
        return;
    }
    // Displays all stored employees in a formatted list
    printf("\n===== Employee List =====\n");

    for (int i = 0; i < count; i++) {
        printf("\n--- Employee %d ---\n", i + 1);
        printf("ID: %d | Name: %s | Salary: %.2f | Hired: %02d-%02d-%d\n",
               employees[i].id,
               employees[i].name,
               employees[i].salary,
               employees[i].hired.day,
               employees[i].hired.month,
               employees[i].hired.year);
    }
}

Employee *search_employee(Employee *employees, int count, int id) {
    for(int i = 0; i < count; i++) {
        if(employees[i].id == id) {
            return &employees[i];
        }
    }
    return NULL;
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

int give_raise(Employee *emp, float percent_raise) {
    emp->salary += emp->salary * (percent_raise / 100.0);
    return 1;
}

int remove_employee(Employee *employees, int *count, int id){
    int i, j;
    for(i = 0; i < *count; i++) {
        if(employees[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            return 1; // if successful
            
        }
    }
    return 0; // if not successful
}