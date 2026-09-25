<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Secure Data Handling Lab

## Table of Contents :

  - [0. Codebase Familiarization (Analysis Only)](#subparagraph0)
  - [1. Fix Ownership of Session Fields](#subparagraph1)
  - [2. Safe Updates of Session Data](#subparagraph2)
  - [3. Harden Store Insertion and Failure Handling](#subparagraph3)
  - [4. Safe Deletion and Lifetime Handling](#subparagraph4)
  - [5. Full Cleanup and Lifecycle Hardening](#subparagraph5)
  - [6. Final Regression Suite](#subparagraph6)
## Introduction and Context

Many real-world security vulnerabilities do not come from obvious buffer overflows, but from **incorrect handling of dynamically allocated data inside data structures**.

Common problems include:

* memory that is freed while still referenced,
* memory that is never freed,
* ownership rules that are unclear or inconsistent,
* cleanup code that works only in the “happy path”.

In this lab, you will work with a small C codebase that implements an in-memory data store using dynamic data structures. The program appears to work correctly, but it contains **security-relevant memory management flaws**.

Your task is to **identify and fix these issues** by correcting how memory ownership, lifetime, and cleanup are handled.

The final result must be a **secure, memory-safe implementation**.

---

## Learning Objectives

By completing this project, you will be able to:

* Reason about **ownership and lifetime** of heap-allocated structures.
* Identify and fix security-relevant memory bugs such as:
	* memory leaks,
	* use-after-free,
	* double free,
	* lost pointers.
* Apply **dynamic analysis** to validate memory safety.
* Implement safe creation, update, and destruction of data structures.
* Understand why incorrect data handling is a **security problem**, not just a correctness issue.

---

## Resources

You are expected to consult official documentation and prior knowledge as needed.

Recommended references:

* Valgrind documentation
  [https://valgrind.org/docs/](/rltoken/kim7JfUTizQ8B95-w9n9qg)
* GNU GDB documentation
  [https://www.gnu.org/software/gdb/documentation/](/rltoken/4Qjk5k7z_FhVH7X_OQ04Pg)
* CERT C Secure Coding Standard (memory-related rules)
  [https://wiki.sei.cmu.edu/confluence/display/c](/rltoken/_MXLQA_leaS2_jSOopGiKg)

---

## Requirements and Constraints

### General Rules

* You must **not change the public API** (function names, signatures).
* You must **not change the CLI behavior**.
* Your fixes must be done in:
	* `session.c`
	* `store.c`
* You may update headers only if strictly necessary for correctness.

### Build Requirements

Your code must compile cleanly with:

```
gcc -std=gnu89 -Wall -Wextra -Werror -pedantic
```

Compilation warnings are treated as errors.

---

### Functional Requirements

After your fixes:

* All existing CLI commands must continue to work as expected.
* The program must behave correctly under:
	* normal usage,
	* repeated insertions and deletions,
	* clearing the store,
	* program exit.

---

### Memory Safety Requirements

Your final implementation must satisfy all of the following:

* No memory leaks.
* No use-after-free.
* No double free.
* No lost pointers.
* All dynamically allocated memory must have a **clear owner**.
* All owned memory must be freed **exactly once**.

These properties will be validated automatically using dynamic analysis tools.

---

### Use of AI Tools

You may use AI tools (including ChatGPT) **as a support tool** to:

* clarify concepts,
* understand error messages,
* reason about ownership and lifetime.

You must **not** use AI to:

* directly generate the final corrected implementation,
* blindly apply suggested patches without understanding them.

If you cannot explain *why* a fix is correct, you should not apply it.

---

## Final Deliverable

Your submission must include **only the corrected source code**.

No written report or explanation is required.

Your grade depends entirely on whether your code:

* compiles correctly,
* behaves correctly,
* and is memory-safe under dynamic analysis.

---

## Important Note

Any changes to the CLI will be ignored during evaluation.
Your focus must be on **secure data handling inside the data structures**, not on input parsing or UI logic.

---

## Student Bundle (Download)

The following repository contains the complete starter code you will work on:

**[Secure Data Handling Lab – Student Bundle](/rltoken/wmLBDx8k0S6JOQTynubodA)**


### Remember

You are allowed to modify **only**:

* `session.c`
* `store.c`

You must **not** modify:

* `main.c`
* Any header files
* The Makefile
* The CLI behavior

During automated correction:

* The original `main.c` will be restored.
* Any changes to files other than `session.c` and `store.c` will be ignored.

> If your solution depends on modifying `main.c`, it will fail validation.

---


## Task
### 0. Codebase Familiarization (Analysis Only) <a name='subparagraph0'></a>

### Objective

Become familiar with the provided codebase and understand **what the program does**, **how data flows**, and **which parts you are expected to modify later**.

This task exists to prevent blind trial-and-error fixes in later steps.

### Context

You are working with a small in-memory data store implemented in C. The program uses dynamically allocated data structures and exposes a command-line interface (CLI) to interact with them.

Although the program compiles and runs, it contains **security-relevant memory management issues** that will be fixed incrementally in later tasks.

Before touching the code, you must understand:

* how the program is structured,
* which files contain core logic,
* and how the CLI interacts with the data structures.

### What you must do

1. **Inspect the project structure**

Identify the role of each file:

* `main.c`
* `session.c`
* `store.c`
* header files (`.h`)
* `Makefile`

Determine which files:

* implement business logic,
* define data structures,
* should not be modified.

1. **Build and run the program**

* Compile the project using the provided `Makefile`.
* Run the resulting binary.
* Execute a few basic commands manually (for example: add, get, delete, clear).

You are not expected to fix anything yet.

1. **Understand the data flow**

At a high level, determine:

* how sessions are created,
* how they are stored,
* how they are retrieved and deleted,
* where dynamic memory allocation happens.

Focus on *conceptual flow*, not on fixing bugs.

1. **Identify your future scope**

Make sure it is clear to you that:

* future fixes will be done in `session.c` and `store.c`,
* the CLI (`main.c`) is not part of the fixing scope,
* behavior visible through the CLI must remain unchanged.

### Deliverable

There is **no file to submit** for this task.

Do not modify any source code.

### Completion Criteria

You should move on only when:

* you can explain (to yourself) what each file is responsible for,
* you know where sessions are allocated and freed,
* you know which files you are allowed to modify later.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`

---

### 1. Fix Ownership of Session Fields <a name='subparagraph1'></a>

### Objective

Make session creation/destruction **memory-safe** by correcting ownership and cleanup behavior inside `session.c`.

### Context

A `session_t` stores fields that originate outside the session. If ownership is handled incorrectly, it can lead to:

* freeing memory that the session never allocated,
* leaking memory when construction fails halfway,
* fragile behavior that depends on caller lifetime.

Your goal is to make sessions **self-contained** and safely destructible.

### What you must do

Modify **only** `session.c`.

Focus your investigation on these areas:

* **Creation path:** identify whether the session depends on caller-provided memory staying valid after `session_create` returns.
* **Failure paths:** identify what happens when one allocation succeeds and a later allocation fails.
* **Destruction path:** identify whether `session_destroy` could free something that was not allocated by the session itself.

### Constraints

* You may modify **only** `session.c`.
* Do not change headers or function signatures.
* CLI behavior must remain unchanged.
* Must compile with strict flags (`-Wall -Wextra -Werror -pedantic -std=gnu89`).

### Completion Criteria (what “done” means)

Your code should:

* compile cleanly,
* run correctly under the CLI,
* show **no invalid frees** and **no leaks** in dynamic analysis during create/destroy scenarios.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `session.c`

---

### 2. Safe Updates of Session Data <a name='subparagraph2'></a>

### Objective

Make session data updates **robust and memory-safe** inside `session.c`, especially when resizing buffers.

### Context

Updating heap buffers is a common source of security bugs. Typical failure modes include:

* losing the only pointer to allocated memory,
* leaving the object in a partially updated state after an operation fails,
* mishandling “clear” operations that should release memory safely.

### What you must do

Modify **only** `session.c`.

Focus your investigation on the update function that changes the session’s data buffer:

* Look for a place where a pointer is **replaced** during resizing.
* Consider what happens if a resize operation fails.
* Look for places where metadata (such as length) might be updated **even if the memory operation didn’t succeed**.
* Confirm that the function correctly supports the “clear data” behavior (data length becomes zero and memory is released).

### Constraints

* You may modify **only** `session.c`.
* Do not change headers or function signatures.
* CLI behavior must remain unchanged.
* Must compile with strict flags (`-Wall -Wextra -Werror -pedantic -std=gnu89`).

### Completion Criteria

Your code should:

* compile cleanly,
* preserve correct CLI behavior,
* show **no leaks**, **no invalid reads/writes**, and **no lost pointers** under dynamic analysis when repeatedly updating data.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `session.c`

---

### 3. Harden Store Insertion and Failure Handling <a name='subparagraph3'></a>

### Objective

Eliminate memory-safety issues that occur during **insertion into the store**, especially when insertion fails.

This task is focused on `store_add()` and how it behaves when:

* the ID already exists,
* internal allocations fail,
* inputs are invalid.

### Context

Insertion is a critical point for ownership and lifetime. A common failure pattern in C data structures is:

* an object is created successfully,
* insertion fails (duplicate, allocation failure, etc.),
* the object is neither stored nor cleaned up → **leak**, or later freed incorrectly → **double free**.

You must ensure that insertion failure does not leave behind allocated memory or inconsistent state.

### What you must do

Modify **only** `store.c`.

While analyzing `store_add()`, pay attention to:

* What happens to the `session_t *` when insertion **does not** happen.
* Whether duplicate detection can cause allocations to become “orphaned”.
* Whether internal allocation failures (node creation) can leave allocated sessions untracked.
* Whether the function’s behavior implies a consistent ownership rule (even if it is not documented).

Your goal is to make failure paths behave as safely as success paths.

### Constraints

* You may modify **only** `store.c`.
* Do not change headers or function signatures.
* CLI behavior must remain unchanged.
* Must compile with:
`-std=gnu89 -Wall -Wextra -Werror -pedantic`

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `store.c`

---

### 4. Safe Deletion and Lifetime Handling <a name='subparagraph4'></a>

### Objective

Make deletion from the store **memory-safe** under all supported deletion scenarios, without breaking normal CLI behavior.

This task focuses on ensuring that deletion does **not**:

* expose freed memory to callers,
* free the same object twice across different cleanup paths,
* leave behind dangling links in the list.

### Context

Deletion is one of the easiest places to introduce security bugs in C data structures:

* removing a node but keeping a pointer to freed memory,
* freeing an object while another part of the program still assumes it exists,
* deleting a node but forgetting to detach it correctly,
* mixing “remove” semantics with “destroy” semantics.

The tricky part is that deletion can be used in two styles:

* delete-and-destroy immediately
* delete-and-return (transfer ownership)

Your implementation must behave safely and predictably.

### What you must do

Modify **only** `store.c`.

When investigating `store_delete()`:

* Identify what the function does with the session pointer it removes.
* Look at the role of the `out` parameter (including the case where it is `NULL`).
* Ensure your deletion logic does not make it possible to:
access a session after it has been destroyed,
destroy the same session again later via another cleanup path.
* Confirm the linked list remains structurally correct after deletion (head deletion vs middle deletion).

### Constraints

* You may modify **only** `store.c`.
* Do not change headers or function signatures.
* CLI behavior must remain unchanged.
* Must compile with:
`-std=gnu89 -Wall -Wextra -Werror -pedantic`

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `store.c`

---

### 5. Full Cleanup and Lifecycle Hardening <a name='subparagraph5'></a>

### Objective

Make the store’s cleanup behavior **robust and repeatable**, even under “messy” sequences of operations (multiple clears, deletes, and exits).

This task focuses on ensuring that destruction/cleanup:

* releases all memory that should be released,
* never frees memory twice,
* remains safe even if called repeatedly,
* leaves the store in a predictable state after cleanup.

### Context

In real systems, cleanup code is where security issues often survive:

* cleanup called twice during error handling,
* partial state cleanup after failed operations,
* stale pointers left inside nodes,
* “destroy” working only once but failing in repeated lifecycles.

Your goal is to harden the **lifecycle invariants** of the store:

* after cleanup, the store should be empty and reusable
* cleanup should be safe even when the store is already empty

### What you must do

Modify **only** `store.c`.

Focus your investigation on:

* The function responsible for releasing the entire store.
* Whether the store is left in a valid empty state afterward.
* Whether cleanup is safe if called multiple times (directly or indirectly).
* Whether cleanup behaves correctly even if internal nodes are partially populated (defensive behavior).

### Constraints

* You may modify **only** `store.c`.
* Do not change headers or function signatures.
* CLI behavior must remain unchanged.
* Must compile with:
`-std=gnu89 -Wall -Wextra -Werror -pedantic`

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `store.c`

---

### 6. Final Regression Suite <a name='subparagraph6'></a>

### Objective

Confirm that your final implementation is stable and does not introduce regressions across the key security and correctness goals of the lab.

This stage validates the most meaningful behaviors from earlier tasks as a single integrated checkpoint.

### What you must do

No new work is required beyond submitting your final code.

Your submission must already include all fixes from previous tasks in:

* `session.c`
* `store.c`

### How your work will be validated (automatic)

A regression suite will be executed against your code. It will cover the most important outcomes:

#### Build Discipline

* The project must compile cleanly with strict compiler settings (warnings treated as errors).

#### Correct Store Lifecycle

* Insert multiple sessions, retrieve them, delete some, clear the store, and repeat.
* After cleanup operations, the store must remain usable and behave consistently.

#### Failure-Path Safety

* Duplicate insert attempts must behave correctly and must not leak memory.
* Invalid operations (e.g., deleting missing IDs) must not corrupt state.

#### Update Safety

* Multiple updates to a stored session’s data must not corrupt memory or leak.
* Clearing session data must behave correctly and remain safe over repeated use.

#### Memory Safety

* Under dynamic analysis, the suite must show:
* no invalid reads/writes,
* no double frees,
* no use-after-free,
* no memory leaks on program exit.

### Completion Criteria

This task is passed if and only if the full regression suite succeeds:

* build passes,
* functional sequences match expected behavior,
* and dynamic analysis reports no memory-safety issues.

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `secure_data_handling`
* File: `session.c, store.c`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
