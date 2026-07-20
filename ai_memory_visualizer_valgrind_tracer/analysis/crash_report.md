# Crash Report

## Program
`crash_example.c`

## Description of the crash
The program prints `requesting n=0`, then terminates immediately with a segmentation fault — deterministic on every run, since `n` is hardcoded to `0`.
```
$ ./crash_example; echo "exit code: $?"
requesting n=0
Segmentation fault
exit code: 139        # 128+11 = SIGSEGV
```
Valgrind confirms: `Invalid write of size 4 ... Address 0x0 is not stack'd, malloc'd or (recently) free'd`, at `crash_example.c:32`.

## Invalid access
Line 32: `nums[0] = 42;` — a write to address `0x0`. Valgrind confirms this address was never valid memory of any kind (not stack, not heap, not freed).

## Stack or heap?
Neither, directly. `nums` (the pointer *variable*) lives on the stack. The value it holds (`NULL`) was meant to reference a heap object that was never created. The faulting address `0x0` belongs to no region.

## Root cause (causal chain)
1. `main` hardcodes `n = 0`.
2. `allocate_numbers(0)` hits `if (n <= 0) return NULL;` — returns before `malloc` is ever called.
3. `main` assigns `nums = NULL`, with no check.
4. `nums[0] = 42;` dereferences NULL → page fault → `SIGSEGV`.

## Why it's invalid
Address `0x0` is deliberately left unmapped in every process (standard OS convention), so any dereference of it faults immediately, regardless of allocator or timing.

## Category of undefined behavior
**NULL-pointer dereference** — distinct from use-after-free, buffer overflow, or uninitialized-memory use.

## AI suggestions and critique
AI proposed three causes from source alone:
1. ❌ *"nums array is too small — allocate more memory."* Wrong: no allocation ever happens on this path.
2. ❌ *"Possible stack overflow if n is negative."* Wrong/speculative: `n` is hardcoded `0`, never negative, no such indexing exists.
3. ✅ *"NULL dereference — return value never checked."* Correct, matches Valgrind's `Address 0x0` report exactly.

The two wrong guesses were generic "segfault" patterns not grounded in this code or the actual fault address.

## Suggested fix (optional, not applied)
```c
nums = allocate_numbers(n);
if (!nums)
    return 1;
```

