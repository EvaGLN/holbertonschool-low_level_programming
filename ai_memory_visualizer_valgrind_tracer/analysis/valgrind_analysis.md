# Valgrind Analysis

Tool: `valgrind-3.26.0`
Flags used: `--track-origins=yes` on all four programs, plus `--leak-check=full --show-leak-kinds=all` on `stack_example`, `heap_example`, and `aliasing_example` (omitted for `crash_example` since it terminates via `SIGSEGV` before any leak summary would be meaningful beyond the heap summary).

This document classifies every Valgrind-reported issue, names the exact memory object involved, and explains the lifetime violation that caused it — cross-referenced against the static memory maps produced in `analysis/memory_maps.md`. AI-generated interpretations were used only as a first pass and are checked against the actual Valgrind output and the source below; one confirmed AI error is documented in Section 5.

## Table of Contents
1. [stack_example.c](#1-stack_examplec)
2. [heap_example.c](#2-heap_examplec)
3. [aliasing_example.c](#3-aliasing_examplec)
4. [crash_example.c](#4-crash_examplec)
5. [AI Interpretation Errors](#5-ai-interpretation-errors)
6. [Summary table — all issues](#6-summary-table--all-issues)

---

## 1. stack_example.c

```
==41477== HEAP SUMMARY:
==41477==     in use at exit: 0 bytes in 0 blocks
==41477==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==41477== All heap blocks were freed -- no leaks are possible
==41477== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

**Classification:** No errors reported. Clean run.

**Analysis:** The "1 allocs, 1 frees, 1,024 bytes" refers to glibc's own internal stdio buffer (allocated lazily on the first `printf` call, freed automatically during normal `exit()` cleanup) — not anything allocated by this source file. This confirms the memory-map prediction: `stack_example.c` never calls `malloc`/`free` itself; every object in it (`local_int`, `local_buf`, `marker`, `p_local`) is a stack-frame local, and Valgrind's heap tracker has nothing of the program's own to flag. This run serves as the control case validating that Valgrind agrees with the static trace.

---

## 2. heap_example.c

```
==41933== 6 bytes in 1 blocks are definitely lost in loss record 1 of 1
==41933==    at 0x4850858: malloc (vg_replace_malloc.c:447)
==41933==    by 0x4001211: person_new (heap_example.c:21)
==41933==    by 0x40012FA: main (heap_example.c:51)
==41933== LEAK SUMMARY:
==41933==    definitely lost: 6 bytes in 1 blocks
==41933==    indirectly lost: 0 bytes in 0 blocks
==41933==      possibly lost: 0 bytes in 0 blocks
==41933==    still reachable: 0 bytes in 0 blocks
==41933== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

### Issue #1

| Field | Value |
|---|---|
| **Error type** | Memory leak — classified by Valgrind as **"definitely lost"** |
| **Memory object** | The 6-byte block allocated at `heap_example.c:21` (`p->name = malloc(len + 1);` inside `person_new`), holding `"Alice\0"` |
| **Allocation site** | `person_new` at line 21, called from `main` at line 51 (the `alice = person_new("Alice", 30);` call site) |
| **Root cause / lifetime violation** | **Leak due to lost ownership.** The only pointer that ever referenced this block was `p->name` (a field inside the `Person` struct at `alice`). `person_free_partial(alice)` calls `free(p)` on the *struct* only, at which point the struct — and with it the last reference to the 6-byte string block — is gone. No code path ever calls `free(alice->name)` before that. The block becomes permanently unreachable from any pointer still visible to the program, meeting Valgrind's precise definition of "definitely lost" (no pointer anywhere in the process, reachable or not, refers to it any longer). |

**Verification against the memory map:** This matches `memory_maps.md` Section 2 exactly — the map predicted `alice->name` as leaked based on static reading of `person_free_partial`'s body (it only calls `free(p)`, never touching `p->name`). Valgrind's `definitely lost: 6 bytes in 1 blocks` confirms the prediction with a runtime measurement, and the call stack (`person_new:21` ← `main:51`) confirms this is specifically Alice's string, not Bob's (Bob's string was freed correctly and does not appear in the leak summary).

**Note on total heap usage:** `5 allocs, 4 frees, 1,066 bytes allocated` — 42 bytes belong to the program (`16+6+16+4` for alice's struct+name and bob's struct+name), and the remaining 1,024 bytes are the same libc stdio buffer seen in `stack_example`. Unlike `crash_example` below, this program exits normally (`return 0;`), so the stdio buffer's own allocation is cleanly freed during `exit()` — accounting for the 4th free beyond the program's 3 explicit `free()` calls (`bob->name`, `bob`, `alice`).

---

## 3. aliasing_example.c

```
==42242== Invalid read of size 4
==42242==    at 0x40012F2: main (aliasing_example.c:42)
==42242==  Address 0x4a93488 is 8 bytes inside a block of size 20 free'd
==42242==    at 0x48538BF: free (vg_replace_malloc.c:990)
==42242==    by 0x40012CE: main (aliasing_example.c:38)
==42242==  Block was alloc'd at
==42242==    at 0x4850858: malloc (vg_replace_malloc.c:447)
==42242==    by 0x40011E4: make_numbers (aliasing_example.c:12)
==42242==    by 0x4001272: main (aliasing_example.c:30)

==42242== Invalid write of size 4
==42242==    at 0x4001312: main (aliasing_example.c:44)
==42242==  Address 0x4a9348c is 12 bytes inside a block of size 20 free'd
==42242==    ... (same free/malloc call stack)

==42242== Invalid read of size 4
==42242==    at 0x4001320: main (aliasing_example.c:45)
==42242==  Address 0x4a9348c is 12 bytes inside a block of size 20 free'd
==42242==    ... (same free/malloc call stack)

==42242== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
==42242== All heap blocks were freed -- no leaks are possible
```

### Issue #1

| Field | Value |
|---|---|
| **Error type** | **Use-after-free** — invalid read |
| **Memory object** | The 20-byte `int[5]` block allocated in `make_numbers` (line 12), aliased by both `a` and `b` in `main` |
| **Faulting line** | `aliasing_example.c:42` → `printf("  reading b[2]=%d\n", b[2]);` |
| **Root cause / lifetime violation** | `b[2]` is `*(b + 2)`, an access 8 bytes into the block (`0x4a93488` = block base `0x4a93480` + 8). The block's lifetime ended at line 38 (`free(a)`), but `b` — an alias created earlier via `b = a;` — was never invalidated. This is a **read through a dangling alias**: the object's lifetime ended, but a second pointer variable referencing the same object was not updated, so the program treats freed memory as if it were still live. |

### Issue #2

| Field | Value |
|---|---|
| **Error type** | **Use-after-free** — invalid write |
| **Memory object** | Same 20-byte block, offset 12 (`0x4a9348c` = base + 12) |
| **Faulting line** | `aliasing_example.c:44` → `b[3] = 1234;` |
| **Root cause / lifetime violation** | Same dangling-alias condition as Issue #1, but a **write** rather than a read — strictly more dangerous, since a write to freed memory can corrupt the allocator's own free-list bookkeeping, or silently corrupt a different live object if the block had already been reallocated elsewhere by the time this line ran. |

### Issue #3

| Field | Value |
|---|---|
| **Error type** | **Use-after-free** — invalid read |
| **Memory object** | Same 20-byte block, offset 12 |
| **Faulting line** | `aliasing_example.c:45` → `printf("  wrote b[3]=%d\n", b[3]);` |
| **Root cause / lifetime violation** | Reads back the value just written by Issue #2's invalid write. Still an invalid access in Valgrind's eyes regardless of what value comes back, since the underlying block remains freed. |

**All three errors share one root cause:** `free(a)` at line 38 ends the block's lifetime, but `b` (an alias of `a`, not a separate allocation) is never reassigned or nulled. Every subsequent access through `b` is a use-after-free, independent of whether the specific byte pattern happens to look "correct" — see Section 5 for why that last point matters.

**Leak summary:** `All heap blocks were freed -- no leaks are possible` — correctly, there is no leak here; the block was freed exactly once (`free(a)`), just accessed illegally afterward. This is a lifetime-of-access violation, not a lifetime-of-allocation violation, and it's important to keep those two categories distinct in this report.

---

## 4. crash_example.c

```
==42116== Invalid write of size 4
==42116==    at 0x400128A: main (crash_example.c:32)
==42116==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==42116== Process terminating with default action of signal 11 (SIGSEGV)
==42116==  Access not within mapped region at address 0x0
==42116== HEAP SUMMARY:
==42116==     in use at exit: 1,024 bytes in 1 blocks
==42116==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==42116== LEAK SUMMARY:
==42116==    definitely lost: 0 bytes in 0 blocks
==42116==    still reachable: 1,024 bytes in 1 blocks
==42116== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

### Issue #1

| Field | Value |
|---|---|
| **Error type** | **Invalid write / NULL-pointer dereference**, fatal (`SIGSEGV`) |
| **Memory object** | No object — address `0x0`, explicitly reported as `not stack'd, malloc'd or (recently) free'd`, i.e. never a valid object of any kind |
| **Faulting line** | `crash_example.c:32` → `nums[0] = 42;` |
| **Root cause / lifetime violation** | Not a lifetime violation in the usual sense (nothing was ever allocated and later misused) — this is a **missing-allocation-check violation**. `allocate_numbers(0)` takes the `n <= 0` early-return branch and returns `NULL` without ever calling `malloc`. `main` assigns this `NULL` to `nums` and dereferences it unconditionally. Valgrind's memory checker and the OS's page-fault mechanism agree here: address 0 is never a valid object, so this is flagged before the crash even completes, and then the crash itself terminates the process. |

### Issue #2 (heap summary anomaly, not a program error)

| Field | Value |
|---|---|
| **Classification** | `still reachable: 1,024 bytes in 1 blocks` — explicitly **not** counted under "definitely/indirectly/possibly lost" |
| **Memory object** | glibc's internal stdio buffer, allocated on the first `printf` call |
| **Root cause** | This is **not a bug in the program's own logic.** The process is killed mid-execution by `SIGSEGV` before `exit()` ever runs, so libc's normal cleanup path (which would free this buffer, as seen happening in `heap_example.c`'s successful exit) never gets a chance to execute. Valgrind correctly distinguishes this as "still reachable" (a valid pointer to it existed right up until the crash) rather than "lost," because the pointer to it was never actually dropped — the program just never got to use it. |

**Comparing this run to `heap_example.c`'s normal exit** is what makes clear that the 1,024-byte stdio block is a constant across all four programs (every one of them calls `printf`), and its "still reachable" vs. "freed" status depends purely on whether the process reaches a normal `exit()` — a useful confirmation that this figure is not something to chase down as a bug in any of the four `.c` files.

---

## 5. AI Interpretation Errors

Per the assignment requirement, at least one case where an AI-generated explanation was checked against real Valgrind output and found wrong.

### Error: overconfident claim about the value of `b[2]` after `free()` — contradicted by two real runs of the same program

**What AI claimed**, in the prior `memory_maps.md` correction, after seeing only one earlier run:
> "Any read from within the first 16 bytes of a freed tcache chunk should be expected to return allocator bookkeeping, not the pointer's original contents, even before any reuse by another `malloc()`." — presented as the corrected, reliable rule.

**Why this is wrong:** Comparing the two actual runs pasted in this conversation shows the outcome is **not deterministic**:

| Run | `free(a)` block address | `reading b[2]` result |
|---|---|---|
| Earlier run (used for the first correction) | `0x61d3705c4420` | `1826454939` (garbage — metadata) |
| This run, under Valgrind | `0x4a93480` | `22` (the original value, unchanged) |

Both are the same source file, same allocation size (20 bytes), same use-after-free bug — yet one run returned corrupted allocator metadata at that offset and the other returned the untouched original value. My prior explanation stated the corrupted outcome as the *expected*, reliable result, which the second run directly contradicts.

**Why the real behavior varies:** Whether glibc's tcache actually writes its `next`/`key` bookkeeping fields into a freed chunk depends on allocator-internal state at the moment of `free()` — specifically, whether that chunk is routed into a tcache bin at all (each per-size tcache bin holds at most 7 entries by default; a chunk can also be merged with adjacent free space, go to a fast bin, or interact with the top chunk depending on prior allocator activity in the process). This program only ever performs one allocation of this size, so the exact bin state — and therefore whether the first 16 bytes get overwritten — is sensitive to build/runtime details (ASLR-affected heap base is one visible symptom: the block sits at a different address in each run) that are not fully predictable from source code alone.

**Correct statement:** Reading or writing through a dangling pointer after `free()` is undefined behavior whose *specific byte-level outcome is unreliable and run-dependent* — it may return the original data unchanged, corrupted allocator metadata, or (if the block has been reused) another live object's data. The bug itself (the access is illegal) is deterministic and always flagged by Valgrind; the *value observed* is not. My earlier explanation conflated "Valgrind will always flag this" (true) with "the value will always look like corrupted metadata" (false, per the second run's own data).

---

## 6. Summary table — all issues

| Program | Line | Valgrind classification | Object | Category |
|---|---|---|---|---|
| stack_example.c | — | none | — | clean (stack-only, no heap use) |
| heap_example.c | 21 (alloc), leaked at exit | definitely lost, 6 bytes | `alice->name` string block | leak due to lost ownership (struct freed before its owned field) |
| aliasing_example.c | 42 | invalid read of size 4 | `int[5]` block, offset 8 (`b[2]`) | use-after-free (dangling alias read) |
| aliasing_example.c | 44 | invalid write of size 4 | same block, offset 12 (`b[3]`) | use-after-free (dangling alias write) |
| aliasing_example.c | 45 | invalid read of size 4 | same block, offset 12 (`b[3]`) | use-after-free (dangling alias read) |
| crash_example.c | 32 | invalid write, fatal SIGSEGV | address `0x0` (no object) | NULL-pointer dereference (missing return-value check) |
| crash_example.c | — | still reachable, 1,024 bytes | libc stdio buffer | not a program bug — cleanup skipped due to abnormal termination |

