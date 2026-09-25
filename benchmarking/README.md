<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Green Tech Efficiency & Benchmarking Lab

## Table of Contents :

  - [0. Baseline Execution Measurement](#subparagraph0)
  - [1. Algorithmic Efficiency Comparison](#subparagraph1)
  - [2. Controlled Instrumentation Experiment](#subparagraph2)
  - [3. Written Report](#subparagraph3)
## Introduction and Context

Software efficiency is not an abstract concern. Inefficient programs keep the CPU active longer, which typically increases energy consumption at scale. Professional energy profiling requires specialized tooling, but developers can already make responsible decisions using **basic performance measurement** and **controlled experiments**.

This project introduces benchmarking as an engineering practice: you will run predefined C programs, measure execution time, compare implementations, and reason about what the results mean in terms of efficiency and sustainability.

This is not an optimization contest. The focus is on **measurement discipline** and **evidence-based reasoning**.

---

## Learning Objectives

By completing this project, you will be able to:

* Compile C programs using strict compiler flags and interpret failures.
* Measure execution time using `clock()` and interpret timing variability.
* Compare two implementations fairly under controlled conditions.
* Explain how algorithmic efficiency connects to runtime and energy usage.
* Write a short technical report grounded in your own measurements.

---

## Resources

Use the following references to research and validate your work:

* Linux `time` command manual:
  [https://man7.org/linux/man-pages/man1/time.1.html](/rltoken/Xngydh6iAAUrbgQw6jMl2g)
* `clock()` and `CLOCKS_PER_SEC` documentation:
  [https://en.cppreference.com/w/c/chrono/clock](/rltoken/EBeilplWvztMFkzUgOVZpg)
* Intro to algorithm analysis / Big-O (conceptual):
  [https://www.geeksforgeeks.org/analysis-algorithms-big-o-analysis/](/rltoken/D1W3dU2gs8yaj_FPvbu4HA)
* Efficient code and sustainability (conceptual overview):
  [https://hmnshudhmn24.medium.com/the-silent-byte-why-your-codes-carbon-footprint-matters-and-how-to-shrink-it-a434b7ef420c](/rltoken/D5Uh2s8koVRLeYPFL5fyaw)

---

## Requirements

### Compilation

All C files must compile with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long
```

### General Rules

* The provided source files are the starting point.
* Only the instrumentation exercise is intended to be modified.
* No external libraries beyond the C standard library.
* Benchmarking must be executed on the same machine/environment for all measurements.

---

## Notes

* This project does not measure real power draw in watts.
* Runtime is used as a proxy: longer runtime generally implies longer CPU activity.
* A deeper version of this concept will be revisited in a later module using additional tools.


## Task
### 0. Baseline Execution Measurement <a name='subparagraph0'></a>

### Objective

Measure execution time for a deterministic computation to understand timing variability and establish a baseline.

### Instructions

You are provided with: `baseline_loop.c`

```c
#include <stdio.h>
#include <time.h>

#define ITERATION_COUNT 100000000UL

int main(void)
{
    volatile unsigned long long result;
    clock_t start;
    clock_t end;
    double elapsed;
    unsigned long i;

    result = 0;

    start = clock();

    for (i = 0; i < ITERATION_COUNT; i++)
        result += (unsigned long long)(i % 3);

    end = clock();

    elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("Iterations: %lu\n", (unsigned long)ITERATION_COUNT);
    printf("Execution time: %.6f seconds\n", elapsed);

    return 0;
}
```

You must:

* Compile the program using the required flags.
* Execute the program three consecutive times.
* Record the full output of each run verbatim in a file `baseline_loop-metrics.md`.

You must not modify the source file.

> Execution times that are close but not necessarily identical.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `benchmarking`
* File: `baseline_loop-metrics.md`

---

### 1. Algorithmic Efficiency Comparison <a name='subparagraph1'></a>

### Objective

Compare execution time between two predefined implementations solving the same problem.

### Instructions

You are provided with: `comparison_algorithms.c`

```c
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 50000

static int data[ARRAY_SIZE];

static void initialize_data(void)
{
    int i;

    for (i = 0; i < ARRAY_SIZE; i++)
        data[i] = i;
}

static int count_even_naive(void)
{
    int count;
    int i;
    int j;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (data[j] % 2 == 0)
                count++;
        }
    }

    return count;
}

static int count_even_single_pass(void)
{
    int count;
    int i;

    count = 0;

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (data[i] % 2 == 0)
            count++;
    }

    return count;
}

int main(void)
{
    clock_t start;
    clock_t end;
    double elapsed_a;
    double elapsed_b;
    int result_a;
    int result_b;

    initialize_data();

    start = clock();
    result_a = count_even_naive();
    end = clock();
    elapsed_a = (double)(end - start) / (double)CLOCKS_PER_SEC;

    start = clock();
    result_b = count_even_single_pass();
    end = clock();
    elapsed_b = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("Naive algorithm result: %d\n", result_a);
    printf("Naive algorithm time: %.6f seconds\n", elapsed_a);
    printf("Single-pass algorithm result: %d\n", result_b);
    printf("Single-pass algorithm time: %.6f seconds\n", elapsed_b);

    return 0;
}
```

The program prints execution time for two implementations.

You must:

* Compile using the required flags.
* Execute the program at least three times.
* Record the execution times for both implementations.
* Compute the average execution time for each implementation.
* Compute the relative difference (for example: “Implementation A is ~X times slower than B”).
* Write down the results in a file `comparison_algorithms-metrics.md`.

You must not modify algorithm logic, input data, or timing logic. Comments may be added for personal notes.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `benchmarking`
* File: `comparison_algorithms-metrics.md`

---

### 2. Controlled Instrumentation Experiment <a name='subparagraph2'></a>

### Objective

Instrument a multi-phase program and reason about where execution time is spent.

### Instructions

You are provided with: `instrumentation_lab.c`

```c
#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;

    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    unsigned long checksum;

    /* Students must add clock-based timing and print required lines. */

    build_dataset();
    process_dataset();
    checksum = reduce_checksum();

    if (checksum == 0ul)
        printf("impossible\n");

    /* Required output (exact format, no extra lines):
     * TOTAL seconds: <float>
     * BUILD_DATA seconds: <float>
     * PROCESS seconds: <float>
     * REDUCE seconds: <float>
     */

    return 0;
}
```

The program runs multiple phases over a fixed-size dataset stored in static arrays. You must add timing instrumentation using `clock()`.

You must:

* Use `clock_t` and `clock()` from `<time.h>`.
* Convert to seconds using `CLOCKS_PER_SEC`.
* Decide the boundaries of each measurement in a consistent way.
* Keep algorithmic logic unchanged.

### Output Contract

The program must print exactly four lines, in this order, with `%.6f` formatting:

```bash
TOTAL seconds: <float>
BUILD_DATA seconds: <float>
PROCESS seconds: <float>
REDUCE seconds: <float>
```

No additional output is allowed.

### Expected Outcome

* `instrumentation_lab.c` compiles with the required flags.
* The program prints exactly four lines matching the contract.
* `TOTAL` is greater than or equal to each sub-measurement.
* The student can justify measurement boundary choices in the report.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `benchmarking`
* File: `instrumentation_lab.c`

---

### 3. Written Report <a name='subparagraph3'></a>

### Objective

Explain your measurements and conclusions using evidence and clear reasoning.

### Instructions

Create a Markdown document named:

```undefined
green_efficiency_analysis.md
```

Length constraints:

* Minimum: 400 words
* Maximum: 700 words

The file must include the following titled sections:

* **Measurement Methodology**
* **Observed Performance Differences**
* **Relation Between Runtime and Energy Consumption**
* **Limitations of the Experiment**
* **Practical Engineering Takeaway**

All claims must be grounded in your recorded outputs from the provided programs. Speculative statements without measurement support are not acceptable.

### Expected Outcome

* One Markdown file meeting length requirements.
* Explicit references to measured execution times.
* At least one clear limitation stated.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `benchmarking`
* File: `green_efficiency_analysis.md`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
