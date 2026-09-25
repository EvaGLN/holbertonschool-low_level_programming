<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Dynamic Analysis & Reverse Logic with GDB

## Table of Contents :

  - [0. GDB Fundamentals](#subparagraph0)
  - [1. Dynamic Analysis with VS Code](#subparagraph1)
## Introduction and Context

When programs become complex, reading source code line by line is often not enough to understand what they actually do. Conditionals depend on runtime values, state changes over time, and small transformations compound into non-obvious behavior.

**Dynamic analysis** is the practice of understanding a program by observing it *while it runs*.

In this lab, you will:

* Use **GDB (GNU Debugger)** to observe a program’s execution.
* Use **Visual Studio Code** as a graphical interface on top of GDB.

This project is not about bypassing checks or modifying binaries.
It is about **understanding behavior**.

---

## Learning Objectives

By completing this project, you will be able to:

* Use GDB to:

  * run a program under controlled execution,
  * set breakpoints,
  * step through code,
  * inspect variables and function arguments,
  * observe control flow decisions.
* Use Visual Studio Code as a debugging frontend while understanding the underlying debugger behavior.
* Infer an algorithm by observing runtime behavior rather than guessing from source code.

---

## Resources

You are expected to consult official documentation as needed.

* GNU GDB Documentation
  [https://www.gnu.org/software/gdb/documentation/](/rltoken/GGD06FuQNXoL1EOfjay3Gw)
* GCC Debugging Options
  [https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html](/rltoken/WXyR538IXQvWbx94-Fu7dA)
* Visual Studio Code C/C++ Debugging
  [https://code.visualstudio.com/docs/cpp/cpp-debug](/rltoken/sWTnA95wH_LwIf52Upx_Sw)
	
> For this project you'll use this code: [source.c](https://github.com/hbtn-edu/public_resources/blob/main/3776-dynamic_analysis/source.c)

---

## Final Note

This project is designed to force you to **observe before concluding**.

Dynamic analysis rewards patience and precision.
Guessing produces fragile results.

Choose accordingly.


## Task
### 0. GDB Fundamentals <a name='subparagraph0'></a>

### Objective

Use **GDB from the command line** to control execution and extract **specific runtime values** from a running C program.

This task validates your ability to:

* stop execution at precise moments,
* inspect runtime state,
* and extract correct values from a program while it is executing.

### Warm-up (required)

Before working on the provided code, complete the following tutorial end-to-end:

```text
https://www.geeksforgeeks.org/c/gdb-step-by-step-introduction/
```

This tutorial is **practice only**. Do not include tutorial output in your submission.

## Program Provided

You will receive a file named:

* `source.c`

You must **not modify this file** in any way.

## Program Input (fixed)

Run the program using the following input **exactly**:

```text
123456
```

(The newline produced by pressing Enter is expected.)

## What you must submit

### File name (exact)

You must submit a single file named:

```undefined
gdb_fundamentals.txt
```

### Output format (strict)

Your file must contain **exactly 3 lines**, in this order:

* Each line must be a **32-bit unsigned value**
* Format must be:
`0x` followed by **8 uppercase hexadecimal digits**
* No labels
* No comments
* No extra whitespace
* No extra lines

Example format (illustrative only):

```text
0x1234ABCD
0x00000001
0xDEADBEEF
```

## Values to extract (what and when)

You must run the program under **GDB** and extract the following values **at the specified execution moments**.

You are **not told** which GDB commands to use. Determining how to reach these states is part of the task.

### Line 1 — `TAG_ACC` (32-bit)

**Where / when:**

* Inside the function `derive_key(...)`
* Immediately **after** the loop that iterates over the decoded tag finishes
* **Before** the code combines the accumulator with `user_pin` and `g_state`

**What to record:**

* The value of the local variable:
* `x`

Write it as `0x????????`.

### Line 2 — `KEY` (32-bit)

**Where / when:**

* Still inside `derive_key(...)`
* Immediately **before the function returns**

**What to record:**

* The value that will be returned by `derive_key(...)`
* The local variable holding that value:
* `x`

Write it as `0x????????`.

### Line 3 — `ACC_AFTER_I0` (32-bit)

**Where / when:**

* Inside the function `compute_target(...)`
* During the loop
* At the end of the iteration where:
* `i == 0`
* After the accumulator has been fully updated for that iteration

**What to record:**

* The value of the local variable:
* `acc`

Write it as `0x????????`.

## Constraints

* You must **not**:
* modify `source.c`
* add print statements or logging
* hardcode values into the output file
* All values must be obtained through **runtime inspection**.
* The output must be reproducible by repeating your debugging steps.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `dynamic_analysis`
* File: `gdb_fundamentals.txt`

---

### 1. Dynamic Analysis with VS Code <a name='subparagraph1'></a>

### Objective

Use **Visual Studio Code as a debugging interface** (backed by **GDB**) to extract additional runtime values from the provided program at precise execution moments.

This task focuses on using a friendlier UI to:

* navigate execution state,
* pause at the right moments,
* and reliably extract values that depend on runtime control flow.

## Context (what you’ll use in this task)

You will use the VS Code debugger features that map directly to what GDB does:

* **Breakpoints**: pause execution at a specific line or function.
* **Step Over / Step Into / Step Out**: advance execution with different levels of detail.
* **Variables panel**: inspect local variables, arguments, and globals.
* **Call Stack panel**: see the active stack frames and jump between them.
* **Watch expressions**: pin a variable/expression so you can track it while stepping.

You are not expected to know every debugger feature—only enough to stop at the correct moments and read correct values.

## Program Provided

You will receive:

* `source.c`

You must **not modify** this file.

## Program Input (fixed)

Run the program using this exact input:

```text
123456
```

## What you must submit

### File name (exact)

Submit a single file named:

```undefined
gdb_vsc.txt
```

### Output format (strict)

Your file must contain **exactly 4 lines**, in this exact order:

* Lines 1–2: **32-bit unsigned values** formatted as
`0x` + **8 uppercase hex digits**
* Lines 3–4: **16-bit unsigned values** formatted as
`0x` + **4 uppercase hex digits**
* No labels, no extra spaces, no extra lines.

Example format (illustrative only):

```text
0x1234ABCD
0xDEADBEEF
0x00FF
0x1234
```

## Values to extract (what and when)

You must obtain the following values using the VS Code debugger UI while the program runs under GDB.

You are **not told** the exact steps/buttons/commands to reach the required points. You must determine how to stop at the correct moments and inspect the correct variables.

### Line 1 — `TGT_PRE_BRANCH` (32-bit)

**Where / when:**

* Inside the function `validate(...)`
* Immediately **after** the call to `compute_target(k)` returns
* **Before** the conditional branch that checks `(tgt & 1u)` modifies `tgt`

**What to record:**

* The current value of the local variable:
* `tgt`

Write it as `0x????????`.

### Line 2 — `TGT_POST_BRANCH` (32-bit)

**Where / when:**

* Still inside `validate(...)`
* Immediately **after** the `(tgt & 1u)` branch has executed and `tgt` has been updated
* **Before** `mask` and `sig` are computed

**What to record:**

* The value of:
* `tgt`

Write it as `0x????????`.

### Line 3 — `MASK` (16-bit)

**Where / when:**

* Inside `validate(...)`
* Right before the function returns
* After `mask` has been computed

**What to record:**

* The value of:
* `mask`

Write it as `0x????`.

### Line 4 — `SIG` (16-bit)

**Where / when:**

* Same point as Line 3 (right before return)
* After `sig` has been computed

**What to record:**

* The value of:
* `sig`

Write it as `0x????`.

## Constraints

* Do **not** modify `source.c`.
* Do **not** add prints/logging.
* Do **not** hardcode values into the output file.
* Values must be obtained through **runtime inspection in the debugger**.
* Output must match the required format exactly.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `dynamic_analysis`
* File: `gdb_vsc.txt`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
