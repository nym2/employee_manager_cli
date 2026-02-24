#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char name[50];
    float salary;
    Date hired;
} Employee;

int menu();
Employee *add_employee(Employee employees[], int *count, int max, char *name, float salary, Date date_hired);
Employee *find_employee(Employee employees[], int count, char *name);
int remove_employee(Employee employees[], int *count, char *name);
int give_raise(Employee employees[], int count, char *name, float salary);
Employee *oldest_employee(Employee employees[], int count);
void print_all(Employee employees[], int count);



int main(void) {
    Employee employees[100];
    int count = 0;
    int choice;

    do {
        choice = menu();
        switch(choice){
            case 1:
                char name[50];
                float salary;
                Date date_hired;

                printf("Enter employee name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter employee salary: ");
                scanf("%f", &salary);
                getchar();

                printf("Enter date hired\n");
                printf("DAY: ");
                scanf("%02d", &date_hired.day);
                getchar();

                printf("MONTH: ");
                scanf("%02d", &date_hired.month);
                getchar();

                printf("YEAR: ");
                scanf("%04d", &date_hired.year);
                getchar();

                Employee *added = add_employee(employees, &count, 100, name, salary, date_hired);
                if(added != NULL) {
                    printf("Employee added successfully!\n");
                } else {
                    printf("Failed to add employee.\n");
                }
           break;

       case 2:
           char remove_name[50]; 
           printf("Enter employee name to remove: ");
           fgets(remove_name, sizeof(remove_name), stdin);
           remove_name[strcspn(remove_name, "\n")] = '\0';

           if(remove_employee(employees, &count, remove_name)) {
               printf("Employee removed successfully!\n");
           } else {
               printf("Employee not found.\n");
           }
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
    printf("WELCOME TO THE EMPLOYEE MANAGER! PLEASE SELECT AN OPTION\n");
    printf("1. Add Employee\n2. Remove Employee\n3. Give Raise\n4. Find Oldest Employee\n5. Print All Employees\n6. Exit\n");
    scanf("%d", &choice);
    getchar();
    return choice;
}

Employee *add_employee(Employee employees[], int *count, int max, char *name, float salary, Date date_hired) {
    if (*count >= max) {
        printf("Employee limit reached. Cannot add more employees.\n");
        return NULL;
    }
    strcpy(employees[*count].name, name);
    employees[*count].salary = salary;
    employees[*count].hired = date_hired;

    (*count)++;
    return &employees[*count - 1];
}

Employee *find_employee(Employee employees[], int count, char *name) {
    for(int i = 0; i < count; i++) {
        if(strcmp(employees[i].name, name) == 0) {
            return &employees[i];
        }
    }
    return NULL;
}

int remove_employee(Employee employees[], int *count, char *name){
    int i, j;
    for(i = 0; i < *count; i++) {
        if(strcmp(employees[i].name, name) == 0) {
            for(j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            return 1; // success
        }
    }
    return 0; // not found
}