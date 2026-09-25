<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Debugging Visualization with Python Tutor

## Table of Contents :

  - [0. Debugging a Counting Function](#subparagraph0)
  - [1. Debugging Nested Loops](#subparagraph1)
  - [2. Debugging State Across Function Calls](#subparagraph2)
### Introduction and Context

Programs that compile successfully can still be **wrong**. In C, many mistakes are not syntax errors but **logic errors**: loops that run one time too many (or too few), variables that change when they shouldn’t, or values that are never reset.

Debugging is the systematic process of finding and fixing these problems. Instead of guessing or rewriting code blindly, effective debugging relies on **tracing execution step by step** and observing how the program’s state changes over time.

In this project, you will use **Python Tutor’s C visualizer** to debug small C programs. The tool allows you to execute code one line at a time and inspect:

* variable values,
* loop iterations,
* function calls and returns,
* control flow through conditionals.

The goal is not only to fix the code, but to **understand exactly why it was wrong** and how the correction changes the program’s behavior.

---

### Learning Objectives

By completing this project, you will be able to:

* Explain what debugging is and why step-by-step tracing is necessary.
* Use Python Tutor to:
	* execute C code line by line,
	* inspect variable values at each step,
	* follow loop and nested loop execution,
	* observe how functions are called and return values.

* Identify and fix common logic errors involving:
	* off-by-one loop conditions,
	* incorrect loop control variables,
	* improper variable updates,
	* incorrect use of function return values.
  
* Submit corrected C programs that compile cleanly and produce the expected output.

---

### Resources

* **Python Tutor – C Visualizer**
  [https://pythontutor.com/c.html](/rltoken/_cD2Nlad1AdoFawaJKNwrg)

* **Python Tutor – Tool overview**
  [https://pythontutor.com/](/rltoken/JrAgz4GZ2Q0dMumcKb3ytQ)

---

## Project Requirements

These rules apply to all tasks:

* You may only use:
	* variables
	* `if` / `else`
	* loops (`for`, `while`)
	* nested loops
	* functions

* You may **not** use:
	* pointers
	* arrays
	* structs
	* dynamic memory
	* file I/O

* Your code must compile with:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
```

* Output must match **exactly**, including spaces and newlines.
* The checker will compile and run your submitted code independently.

---

### Submission

* Submit the corrected `.c` file for each task.
* Do not add extra output.
* Do not change function names or file names.

**Important:**
If you fix the code without using step-by-step tracing, you are skipping the core skill this project is designed to teach. Debugging is about understanding execution, not guessing.


## Task
### 0. Debugging a Counting Function <a name='subparagraph0'></a>

**Objective** Learn to trace a simple loop and verify a function’s return value.

**Provided file:** `sum_to_n.c`

```c
#include <stdio.h>

int sum_to_n(int n)
{
    int i;
    int sum = 0;

    for (i = 1; i < n; i++)
        sum += i;

    return n;
}

/* -- DO NOT Modify the code below this line -- */

int main(void)
{
    printf("%d\n", sum_to_n(10));
    return 0;
}
```

**Instructions**

1. Open the code in Python Tutor.
2. Run the program step by step.
3. Observe how `i` and `sum` change during the loop.
4. Decide what the function is supposed to compute.
5. Fix the logic so the function returns the correct result.

> **DO NOT CHANGE** the `main` function.

**Expected Outcome**

```text
55
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `intro_debugging`
* File: `sum_to_n.c`

---

### 1. Debugging Nested Loops <a name='subparagraph1'></a>

**Objective** Trace nested loops and identify unintended changes to loop variables.

**Provided file:** `multiplication_table.c`

```c
#include <stdio.h>

void print_table(int size)
{
    int row, col;

    for (row = 1; row <= size; row++)
    {
        for (col = 1; col <= size; col++)
        {
            printf("%d ", row * col);
            col++;
        }
        printf("\n");
    }
}

/* -- DO NOT Modify the code below this line -- */

int main(void)
{
    print_table(4);
    return 0;
}
```

**Instructions**

1. Use Python Tutor to trace execution.
2. Watch how `row` and `col` change inside the nested loops.
3. Identify why some values are skipped.
4. Correct the logic so all products are printed.

> **DO NOT CHANGE** the `main` function.

**Expected Outcome**

```text
1 2 3 4 
2 4 6 8 
3 6 9 12 
4 8 12 16
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `intro_debugging`
* File: `multiplication_table.c`

---

### 2. Debugging State Across Function Calls <a name='subparagraph2'></a>

**Objective** Understand how variable scope and accumulation affect program correctness.

**Provided file:** `row_sums.c`

```c
#include <stdio.h>

int row_sum(int row, int cols)
{
    int c;
    int sum = 0;

    for (c = 1; c <= cols; c++)
        sum += row * c;

    return sum;
}

int total_sum(int rows, int cols)
{
    int r;
    int total = 0;
    int current = 0;

    for (r = 1; r <= rows; r++)
    {
        current += row_sum(r, cols);
        total += current;
    }

    return total;
}

/* -- DO NOT Modify the code below this line -- */

int main(void)
{
    printf("%d\n", total_sum(3, 3));
    return 0;
}
```

**Instructions**

1. Trace the execution of `total_sum` step by step.
2. Observe how `current` and `total` change after each iteration.
3. Decide whether variables are updated at the correct scope.
4. Fix the logic so the program computes the correct total.

> **DO NOT CHANGE** the `main` function.

**Expected Outcome**

```text
36
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `intro_debugging`
* File: `row_sums.c`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
