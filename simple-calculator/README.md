<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# C - Simple Calculator

## Table of Contents :

  - [0. Setup + Skeleton Program](#subparagraph0)
  - [1. Menu Loop + Choice Validation](#subparagraph1)
  - [2. Addition](#subparagraph2)
  - [3. Subtraction](#subparagraph3)
  - [4. Multiplication](#subparagraph4)
  - [5. Division](#subparagraph5)
### Introduction and Context

In this project you will build a terminal-based interactive calculator using the C programming language.

The objective is not to build a complex calculator, but to build a complete program: one that compiles cleanly, runs in a loop, performs correct calculations, and follows a defined interaction contract.

Until now, most exercises focused on isolated concepts (loops, conditionals, functions). This project combines those concepts into a single program that a real user can run.

A central part of this project is learning how input works in C. You will need to research how scanf behaves and understand its limitations. Some input cases are intentionally out of scope for the mandatory tasks and are addressed only in an optional advanced task.

> This project is meant to help you evaluate your current level of autonomy and maturity as a programmer. If something feels harder than expected, that is a useful signal — not a problem.

---

### Learning Objectives

By completing this project, you will be able to:

* Design a small but complete C program from requirements.
* Build a menu-driven application using loops and conditionals.
* Structure code using functions to avoid duplication.
* Implement arithmetic operations using basic language operators.
* Read user input with `scanf`.
* Handle important edge cases such as division by zero.
* Produce C code that compiles with strict compiler settings and no warnings.

---

### Project Expectations

* You are given **requirements and observable behaviors**, not step-by-step instructions.
* You are expected to **research how input works in C** and apply that knowledge.
* You must implement the program incrementally, keeping it working at every step.

This project is intentionally open in implementation. Different correct solutions are possible.

---

### Rules and Constraints (Read Carefully)

* You must **not copy code** from other students, repositories, or tutorials.
* You must **not use AI tools** to generate or modify code.
* Only standard C libraries are allowed. (e.g., `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`)
* **Not allowed:** `math.h` or any external libraries
* The program must compile using strict compiler flags with **zero warnings**.
* All user input must be read using `scanf`.
* You are expected to read integer menu options and numeric operands.
* Arithmetic operations must be implemented using basic operators (`+`, `-`, `*`, `/`).

Breaking these rules defeats the purpose of the project and will invalidate the learning outcome.

---

#### Important Scope Limitation — Input Validation

For the mandatory part of this project, **you are only required to validate**:

- that the menu option is an integer, and
- that the integer value is within the valid menu range.

You are not required to handle non-numeric input (for example: x, hello, 1abc).
If the user enters non-numeric input, your program may fail (for example, by looping indefinitely or behaving unexpectedly). This is intentional and accepted at this stage.

Handling non-numeric input robustly is addressed in an optional advanced task.

---

### Deliverables

* `calculator.c`
* `README.md` including:

  * compile command (exact flags)
  * run instructions
  * supported operations
  * numeric behavior (integer vs decimal)
  * known limitations (if any)

---

### Evaluation Criteria

This project is evaluated primarily on **correctness and discipline**, not on extra features.

The final automated check is simple and strict:

* Your code must compile successfully with the required compiler flags and produce **no warnings**.

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

Program behavior and structure will be reviewed manually.

---

### Academic Integrity

- You must not copy code from other students or public sources.
- You must not use AI tools to generate or modify code.
- Violating these rules defeats the purpose of the project.

---

### What This Project Is (and Is Not)

**This project is:**

* A checkpoint of your current programming maturity
* An opportunity to practice building a complete program
* A controlled environment to struggle with input handling

**This project is not:**

* A speed challenge
* A test of how many features you can add
* A place to optimize or be clever

Keep the scope small. Focus on correctness, clarity, and control over your program.

---

### Final Note

If you finish this project quickly but cannot explain how your input handling works or why your program survives invalid input, then the project has not done its job.

If you finish it more slowly but understand every part of it, then it has.

Take the time.


## Task
### 0. Setup + Skeleton Program <a name='subparagraph0'></a>

### Objective

Ensure the program compiles and runs.

### Requirements

* Print a welcome line.
* Display a menu.
* Allow quitting with option `0`.

### Expected Outcome (example)

```makefile
Simple Calculator
1) Add
2) Subtract
3) Multiply
4) Divide
0) Quit
Choice: 0
Bye!
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---

### 1. Menu Loop + Choice Validation <a name='subparagraph1'></a>

### Objective

Repeat the menu until quit and reject invalid choices.

### Requirements

* The menu must loop.
* If the user enters a number not in the menu, print:

```undefined
Invalid choice
```

* On quitting, print:

```undefined
Bye!
```

### Expected Outcome

```makefile
Choice: 9
Invalid choice
Choice: 0
Bye!
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---

### 2. Addition <a name='subparagraph2'></a>

### Objective

Implement addition end-to-end.

### Requirements

* On choice `1`:
* Prompt for `A:` and `B:`
* Compute `A + B`
* Print:
`Result: <value>`

### Expected Outcome

```makefile
Choice: 1
A: 10
B: 25
Result: 35
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---

### 3. Subtraction <a name='subparagraph3'></a>

### Objective

Implement subtraction.

### Requirements

* On choice `2`, compute `A - B` and print the result.

### Expected Outcome

```makefile
Choice: 2
A: 10
B: 25
Result: -15
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---

### 4. Multiplication <a name='subparagraph4'></a>

### Objective

Implement multiplication.

### Requirements

* On choice `3`, compute `A * B`.

### Expected Outcome

```makefile
Choice: 3
A: 7
B: 6
Result: 42
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---

### 5. Division <a name='subparagraph5'></a>

### Objective

Implement division safely.

### Requirements

* On choice `4`:
* If `B == 0`, print exactly:
`Error:divisionbyzero`
* Otherwise print the division result.

### Expected Outcome

Division by zero:

```vbnet
Choice: 4
A: 10
B: 0
Error: division by zero
```

Normal division (example):

```makefile
Choice: 4
A: 10
B: 4
Result: 2.5
```

> You must decide whether the calculator uses integers or decimals. The behavior must be consistent and documented.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `simple-calculator`
* File: `calculator.c`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
