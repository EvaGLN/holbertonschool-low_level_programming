<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# AI Memory Visualizer + Valgrind Tracer

## Table of Contents :

  - [0. AI Memory Visualizer](#subparagraph0)
  - [1. Valgrind & AI Memory Tracer](#subparagraph1)
  - [2. AI Assisted Crash Report](#subparagraph2)
  - [3. Peer Review Readiness Check](#subparagraph3)
## Introduction & Context

By this point in the module, you have already used pointers, dynamic memory, and recursion. However, *using* memory-related features in C is not the same as **understanding how memory actually behaves at runtime**.

Most critical C bugs are not caused by complex syntax. They are caused by incorrect assumptions about:

* Where data lives (stack vs heap)
* How long that data remains valid
* Which pointer “owns” which memory
* What happens when those assumptions are wrong

This project is designed to expose and correct those assumptions.

You will analyze small C programs that intentionally contain **memory leaks, invalid accesses, aliasing issues, and crashes**. Your task is not simply to observe that something is wrong, but to **explain precisely why it is wrong**, using concrete reasoning about memory layout and lifetime.

Artificial Intelligence tools are allowed and encouraged — but only as **analysis assistants**. AI explanations are often plausible but incomplete or incorrect when it comes to low-level memory behavior. Part of this project is learning to **detect and correct AI mistakes**, not to rely on them blindly.

If you finish this project still thinking “Valgrind says it’s wrong but I don’t really know why”, then the project has failed.

---

## Learning Objectives

After completing this project, you should be able to:

1. **Describe stack and heap memory behavior explicitly**

     * Identify stack frames, local variables, and their lifetimes.
     * Identify heap allocations, ownership, and deallocation responsibility.

2. **Track pointer aliasing and memory ownership**

     * Explain when multiple pointers refer to the same memory.
     * Determine which pointer is responsible for freeing memory (and when).

3. **Interpret Valgrind output accurately**

     * Distinguish between memory leaks, invalid reads/writes, and use-after-free.
     * Map Valgrind diagnostics to specific lines of code and memory states.

4. **Explain segmentation faults deterministically**

     * Identify the invalid memory access that caused the crash.
     * Explain the full causal chain from code → memory misuse → fault.

5. **Use AI critically and professionally**

     * Generate memory explanations and diagrams with AI assistance.
     * Identify inaccuracies, omissions, or incorrect assumptions in AI output.
     * Correct those errors using your own reasoning.

6. **Communicate memory analysis clearly**

     * Produce structured, technical explanations using correct terminology.
     * Avoid vague statements such as “it crashes because the pointer is wrong”.

If you cannot explain a memory bug without running the program again, your understanding is incomplete.

---

## Resources

You are expected to consult documentation and external references as part of the work.

### Required

* **Valgrind User Manual**
  [https://valgrind.org/docs/manual/manual.html](/rltoken/XxBUQisSys31hoVchAvDbA)

* **CERT C Coding Standard – Memory Management (selected sections)**
  [https://cmu-sei.github.io/secure-coding-standards/sei-cert-c-coding-standard/rules/memory-management-mem/mem30-c/)

### Recommended

* Compiler warnings documentation (`-Wall`, `-Wextra`, `-Werror`)
* Articles and references on:
	* Undefined behavior in C
	* Stack vs heap lifetime
	* Use-after-free and dangling pointers

### AI Tools

* Any LLM-based assistant is allowed.
* All AI usage **must be documented and reviewed critically**.
* AI explanations are considered **hypotheses**, not ground truth.

Using AI to replace reasoning rather than support it will negatively affect your evaluation.

---

To complete the tasks in this projects you'll need to download the following repository with the working files:

[Download the zip from GitHub](https://github.com/hbtn-edu/ai_memory_visualizer_valgrind_tracer/archive/refs/heads/main.zip)

**IMPORTANT:** Upload **only** the files in the analysis directory to the required repository, as stated in each task.

### What’s inside

```
.
├── README.md
├── programs/
│   ├── Makefile
│   ├── stack_example.c        # for memory visualizer task (mandatory)
│   ├── heap_example.c         # for memory visualizer (optional) and memory tracer (mandatory) task
│   ├── aliasing_example.c     # for memory visualizer (mandatory) and memory tracer (mandatory) task
│   └── crash_example.c        # for crash report task (mandatory)
└── analysis/
    └── .gitkeep               # Working directory
```

### Build flags

The `Makefile` uses:

* `-Wall -Wextra -Werror -pedantic -std=gnu89 -g`


## Task
### 0. AI Memory Visualizer <a name='subparagraph0'></a>

### Objective

Develop an explicit and correct mental model of how memory behaves in C programs by externalizing it into concrete memory maps, and validating those maps against real program behavior.

This task targets a common failure mode: *believing you understand memory while reasoning implicitly*. That is not sufficient at this stage.

### Context

When working with pointers, most reasoning errors happen silently. You assume a variable is still valid, assume memory still exists, or assume two pointers are independent when they are not.

To counter this, you will use AI tools to generate **step-by-step memory visualizations**, then critically evaluate and correct them. The goal is not to trust AI, but to force incorrect assumptions to surface.

### Instructions

1. Navigate to the `programs/` directory and identify the programs intended for analysis in this task.
2. For each program:

Compile it using the provided `Makefile`.
Run it normally (without Valgrind).
3. Identify key execution points where memory state changes, such as:

Function entry and exit
Recursive calls
Heap allocation and deallocation
Pointer assignments and reassignments
4. Use an AI tool to generate **step-by-step memory maps** that describe:

Stack frames and local variables
Heap allocations
Pointer values and aliases
Object lifetimes
5. Review the AI-generated explanations carefully and **do not assume they are correct**.
6. Manually correct any inaccuracies, missing details, or incorrect assumptions.
7. Write the final, corrected analysis in `analysis/memory_maps.md`.

### Expected Outcome

Your `memory_maps.md` file must:

* Clearly distinguish stack memory from heap memory.
* Explicitly describe variable lifetimes.
* Track pointer aliasing accurately.
* Include at least one documented example where:
The AI explanation was incorrect, incomplete, or misleading.
You explain why it was wrong and how you corrected it.

Vague descriptions such as “the pointer points somewhere invalid” are not acceptable.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `ai_memory_visualizer_valgrind_tracer`
* File: `analysis/memory_maps.md`

---

### 1. Valgrind & AI Memory Tracer <a name='subparagraph1'></a>

### Objective

Learn to interpret Valgrind output as a direct consequence of concrete memory behavior, rather than as abstract diagnostic messages.

This task evaluates whether you can connect **runtime evidence** to **memory reasoning**.

### Context

Valgrind does not find “bugs” by magic. Every reported issue corresponds to a specific memory misuse: an invalid access, a missing deallocation, or an operation on memory whose lifetime has ended.

If you cannot explain *why* Valgrind reports an issue, you do not understand the issue.

### Instructions

1. Run Valgrind on the relevant programs using appropriate flags.
2. Capture all reported issues, including:
Memory leaks
Invalid reads or writes
Use of uninitialized memory
3. For each reported issue:
Identify the type of error.
Identify which memory object is involved.
Explain the lifetime violation or misuse that caused it.
4. Use AI tools to help interpret Valgrind output **only as a starting point**.
5. Independently verify all AI explanations against:
Your code
Your memory maps from Task 1
6. Document your analysis in `analysis/valgrind_analysis.md`.

You are not required to fix the code unless explicitly stated. Analysis is the priority.

### Expected Outcome

Your `valgrind_analysis.md` must:

* Correctly classify each Valgrind warning.
* Map each warning to a specific memory misuse.
* Use precise terminology (e.g., “use-after-free”, “leak due to lost ownership”).
* Include at least one instance where:
An AI explanation was partially or fully incorrect.
You explain why it is incorrect.

Copying Valgrind output without explanation is insufficient.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `ai_memory_visualizer_valgrind_tracer`
* File: `analysis/valgrind_analysis.md`

---

### 2. AI Assisted Crash Report <a name='subparagraph2'></a>

### Objective

Develop the ability to analyze segmentation faults as deterministic outcomes of memory misuse, not as unpredictable crashes.

This task evaluates whether you can reason about failure **without relying on trial-and-error debugging**.

### Context

A segmentation fault is not the bug. It is the final observable effect of undefined behavior that occurred earlier.

Professional engineers are expected to explain crashes precisely, even when they cannot immediately fix them.

### Instructions

1. Run the crashing program and confirm the segmentation fault.
2. Without modifying the code:
Identify the invalid memory access that caused the crash.
Determine whether it involves stack memory, heap memory, or both.
3. Use an AI tool to propose:
Possible causes
Possible fixes
4. Critically evaluate those suggestions:
Which explanations are correct?
Which are speculative or incorrect?
5. Write a structured crash report in `analysis/crash_report.md` that includes:
Description of the crash
Root cause analysis
Explanation of why the memory access is invalid
(Optional) Suggested fix, clearly labeled as such

Do not write “the program crashes because of a segmentation fault.” That is circular and meaningless.

### Expected Outcome

Your `crash_report.md` must:

* Clearly identify the root cause of the crash.
* Explain the full causal chain from code to invalid memory access.
* Correctly identify the category of undefined behavior involved.
* Explicitly critique AI-provided explanations.

If your explanation depends on running the program again, it is incomplete.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `ai_memory_visualizer_valgrind_tracer`
* File: `analysis/crash_report.md`

---

### 3. Peer Review Readiness Check <a name='subparagraph3'></a>

### Objective

Prepare your submission for **cross peer evaluation** by verifying that it demonstrates **real understanding of C memory behavior**, not just correct execution or tool usage.

This task exists so you can validate your own work **before** submitting it for review.

### Context

Your project will be evaluated by another student through **peer cross-review**. Likewise, you will evaluate a peer’s submission.

The evaluation is **global and final**. Individual tasks are not scored separately.

Reviewers will not inspect every detail. They will decide, in a limited time, whether your analysis shows that you **understand what is happening in memory and why**.

If your explanations do not make your understanding obvious, your score will reflect that.

### What Reviewers Will Focus On

Reviewers will evaluate your work based on **reasoning quality**, not presentation.

Before submitting, make sure your work clearly demonstrates the following:

#### 1. Memory Model Understanding

* You clearly distinguish **stack vs heap** memory.
* You explain **when memory becomes invalid**.
* You do not imply that stack memory survives function return.
* You explicitly state **who owns heap memory and who must free it**.

Ask yourself:

> Could someone understand the lifetime of each object by reading my explanation?

#### 2. Pointer & Aliasing Reasoning

* You explicitly explain when multiple pointers refer to the **same memory**.
* You correctly identify **dangling pointers** and **use-after-free** situations.
* Your explanations do not contradict themselves.

Ask yourself:

> Could I explain why a pointer is invalid without running the program again?

#### 3. Valgrind Interpretation

* You correctly identify **what kind of issue** Valgrind reports.
* You explain **why that issue occurs**, not just that it occurs.
* You connect Valgrind output to a specific memory misuse in the code.

Ask yourself:

> If Valgrind output were removed, would my explanation still make sense?

#### 4. Crash Root Cause Explanation

* You explain segmentation faults as **deterministic results**, not accidents.
* You identify **what invalid access happens and when**.
* You avoid circular explanations like “it crashes because of a segfault”.

Ask yourself:

> Could I explain this crash at a whiteboard without tools?

#### 5. Critical Use of AI

* You document how AI was used.
* You identify at least one **AI mistake, omission, or limitation**.
* You explain why that AI output was incorrect or incomplete.

Ask yourself:

> Did I treat AI output as a hypothesis, or as authority?

### What Will *Not* Be Evaluated

You will **not** be evaluated on:

* Whether the code was fixed
* Whether Valgrind reports zero errors
* Whether you used AI or not
* Writing length, verbosity, or formatting style

Only **correctness, clarity, and depth of reasoning** matter.

### Time Constraint Awareness

Your peer reviewer will spend **no more than ~20 minutes** reviewing your work.

If your understanding is not visible quickly and clearly, it will not be inferred.

### Final Self-Check (Before Submission)

Before submitting, confirm that:

* Memory lifetimes are explicitly explained
* Pointer relationships and aliasing are clear
* Valgrind findings are interpreted, not pasted
* Crashes are explained causally
* AI usage is documented and critiqued

If any of these are missing or vague, revise before submission.

> This task is complete when you are confident that **another student can verify your understanding without asking you questions**.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `ai_memory_visualizer_valgrind_tracer`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
