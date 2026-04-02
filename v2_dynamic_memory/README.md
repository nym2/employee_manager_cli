# Employee Manager CLI (C)

A command-line employee management system written in C that demonstrates dynamic memory allocation, pointer manipulation, and structured data handling.
This project is an improved version of a previous static-memory implementation, redesigned to support dynamic resizing using realloc and more scalable data management.

## Features

* Add employees dynamically
* Search employees by ID
* Update employee details (name, salary, hire date)
* Apply percentage-based salary raises
* Remove employees safely (with array shifting)
* Find the oldest employee based on hire date
* Dynamic array resizing using `realloc`

## Concepts Demonstrated

* Dynamic memory management (`malloc`, `calloc`, `realloc`, `free`)
* Pointer manipulation and pass-by-reference
* Structs and nested structs
* Input validation and buffer handling
* Array element shifting (manual memory management)
* Modular function design

## How to Compile & Run

```bash
gcc main.c -o employee_manager
./employee_manager
```

## Sample Usage

```
===== Employee Manager =====
1. Add Employee
2. View Employees
3. Search Employee
4. Update Employee
5. Give Raise
6. Remove Employee
7. Oldest Employee
8. Exit
```

## Why This Project Matters

This project simulates a real-world system where dynamic data must be managed efficiently without high-level abstractions.

It demonstrates strong understanding of:

* Low-level memory control
* Data structures without libraries
* Real-world CLI application design

## Future Improvements

* File persistence (save/load employees)
* Sorting (by salary, hire date)
* Unique ID enforcement
* Modular file separation (.h and .c files)

## Project Evolution

- Version 1: Static array-based employee manager
- Version 2 (current): Dynamic memory version with resizing and improved functionality

## Author

Nympha Pamba  
Aspiring C Developer | Systems Programming Enthusiast
