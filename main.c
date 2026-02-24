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
            case 1: {
                    char name[50];
                    float salary;
                    Date date_hired;

                    printf("Enter employee name: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';

                    printf("Enter employee salary: ");
                    scanf(" %f", &salary);
                    getchar();

                    printf("Enter date hired\n");
                    printf("DAY: ");
                    scanf(" %d", &date_hired.day);
                    getchar();

                    printf("MONTH: ");
                    scanf(" %d", &date_hired.month);
                    getchar();

                    printf("YEAR: ");
                    scanf(" %d", &date_hired.year);
                    getchar();

                    Employee *added = add_employee(employees, &count, 100, name, salary, date_hired);
                    if(added != NULL) {
                        printf("Employee added successfully!\n");
                    } else {
                        printf("Failed to add employee.\n");
                    }
                break;
            } 

       case 2: {
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
        }

       case 3: {
           char raise_name[50];
           float raise_amount;

           printf("Enter employee name to give raise: ");
           fgets(raise_name, sizeof(raise_name), stdin);
           raise_name[strcspn(raise_name, "\n")] = '\0';

           printf("Enter raise amount: ");
           scanf(" %f", &raise_amount);
           getchar();

           if(give_raise(employees, count, raise_name, raise_amount)) {
               printf("Raise given successfully!\n");
           } else {
               printf("Employee not found.\n");
           }
           break;
        }

       case 4: {  
            Employee *oldest = oldest_employee(employees, count);
            if(oldest != NULL) {
                printf("Oldest Employee: %s | Salary: %.2f | Hired: %02d/%02d/%04d\n", oldest->name, oldest->salary, oldest->hired.day, oldest->hired.month, oldest->hired.year);
            } else {
                printf("No employees found.\n");
            }
           break;
        }

       case 5: {
           print_all(employees, count);
           break;
       }
   }

} while(choice != 6);
    return 0;
}

int menu() {
    int choice;
    printf("\n===== Employee Menu =====\n");
    printf("1. Add Employee\n2. Remove Employee\n3. Give Raise\n4. Find Oldest Employee\n5. Print All Employees\n6. Exit\n");
    printf("Enter choice: ");
    scanf(" %d", &choice);
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

int give_raise(Employee employees[], int count, char *name, float salary) {
    Employee *found = find_employee(employees, count, name);
    if(found != NULL) {
        found->salary += salary;
        return 1; // success
    }
    return 0; // not found
}

Employee *oldest_employee(Employee employees[], int count) {
    if(count == 0) return NULL;
    Employee *oldest = &employees[0];

    for (int i = 1; i < count; i++) {

        if (employees[i].hired.year < oldest->hired.year) {
            oldest = &employees[i];
        }
        else if (employees[i].hired.year == oldest->hired.year) {

            if (employees[i].hired.month < oldest->hired.month) {
                oldest = &employees[i];
            }
            else if (employees[i].hired.month == oldest->hired.month) {

                if (employees[i].hired.day < oldest->hired.day) {
                    oldest = &employees[i];
                }
            }
        }
    }

    return oldest;
}

void print_all(Employee employees[], int count) {
    if(count == 0) {
        printf("No employees to display.\n");
        return;
    }
    printf("\nAll Employees:\n");
    for(int i = 0; i < count; i++) {
        printf("%s | Salary: %.2f | Hired: %02d/%02d/%04d\n", employees[i].name, employees[i].salary, employees[i].hired.day, employees[i].hired.month, employees[i].hired.year);
    }
}