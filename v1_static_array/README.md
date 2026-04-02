# Employee Manager CLI (C)

## Description

The **Employee Manager CLI** is a simple command-line application written in **C** that allows users to manage employee records directly from the terminal.

This project demonstrates:

* Use of **structs** to model real-world data
* **Pointers** and pass-by-reference for modifying arrays
* **Dynamic-style management** of records using a fixed-size array
* Input handling with `fgets`, `scanf`, and buffer control
* Searching, updating, and comparing structured data (dates)

---

## Data Model

### `Date`

Stores when an employee was hired.

```c
typedef struct {
    int day, month, year;
} Date;
```

### `Employee`

Represents a single employee record.

```c
typedef struct {
    char name[50];
    float salary;
    Date hired;
} Employee;
```

---

## Features

The program provides a menu-driven interface:

1. **Add Employee**

   * Enter name, salary, and hire date.
2. **Remove Employee**

   * Deletes employee by name.
3. **Give Raise**

   * Adds a salary increment to an existing employee.
4. **Find Oldest Employee**

   * Displays the employee hired earliest.
5. **Print All Employees**

   * Lists all stored employees.
6. **Exit**

   * Closes the program.

---

## How It Works

* Employees are stored in an array:

  ```c
  Employee employees[100];
  ```
* `count` tracks how many employees exist.
* Functions operate on this array using pointers to modify data safely.

Example:

```c
Employee *add_employee(Employee employees[], int *count, int max, ...);
```

The pointer to `count` allows the function to update the total number of employees.

---

## Compilation & Execution

### Compile

```bash
gcc main.c -o employee_manager
```

### ▶Run

```bash
./employee_manager
```

---

## Concepts Practiced

This project reinforces:

* Struct composition (`Employee` contains a `Date`)
* Pointer manipulation (`int *count`)
* Array shifting when deleting records
* Linear search algorithms
* Comparing structured values (year → month → day logic)
* Input-buffer management between `fgets()` and `scanf()`
* Building interactive CLI programs in C

---

## Example Output

```
===== Employee Menu =====
1. Add Employee
2. Remove Employee
3. Give Raise
4. Find Oldest Employee
5. Print All Employees
6. Exit
Enter choice: 1
Enter employee name: Alice
Enter employee salary: 50000
Enter date hired
DAY: 12
MONTH: 03
YEAR: 2020
Employee added successfully!
```

---

## Possible Improvements (Future Work)

* Save/load employees from a file
* Sort employees by salary or hire date
* Add employee ID system
* Input validation for incorrect values
* Dynamic memory allocation instead of fixed array
* Modularize into multiple `.c` and `.h` files

---

## Author
Nympha Pamba.
Built as a learning project to practice **C programming fundamentals, memory handling, and structured data design**.
