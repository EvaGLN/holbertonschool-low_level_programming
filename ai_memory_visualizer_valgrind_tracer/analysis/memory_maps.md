# Memory Maps Analysis

Compiled with: `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -g`
All addresses below are real, taken directly from actual program runs (not simulated).

## Table of Contents
1. [stack_example.c](#1-stack_examplec)
2. [heap_example.c](#2-heap_examplec)
3. [aliasing_example.c](#3-aliasing_examplec)
4. [crash_example.c](#4-crash_examplec)
5. [AI Error Documentation](#5-ai-error-documentation)

---

## 1. stack_example.c

No heap allocation occurs anywhere in this file. Everything below lives on the **stack** only.

### Variables and memory zones

| Variable    | Zone  | Size     | Lifetime |
|---|---|---|---|
| `depth`, `max_depth` (params) | stack | 4 bytes each | created on `walk_stack` entry, destroyed on that call's return |
| `marker`   | stack | 4 bytes  | created on `walk_stack` entry, destroyed on that call's return |
| `local_int`| stack | 4 bytes  | created on `dump_frame` entry, destroyed on return |
| `local_buf`| stack | 16 bytes | created on `dump_frame` entry, destroyed on return |
| `p_local`  | stack | 8 bytes  | created on `dump_frame` entry, destroyed on return, **only valid while its own frame is alive** |

### Stack growth observation (real data)

The stack grows downward (toward lower addresses) as recursion deepens:

| Depth | `&local_int` | `&marker` |
|---|---|---|
| 0 | `0x7ffd4b68e1d4` | `0x7ffd4b68e224` |
| 1 | `0x7ffd4b68e1a4` | `0x7ffd4b68e1f4` |
| 2 | `0x7ffd4b68e174` | `0x7ffd4b68e1c4` |
| 3 | `0x7ffd4b68e144` | `0x7ffd4b68e194` |

Each recursive call drops `&local_int` by exactly `0x30` (48 bytes) — a consistent, fixed-size frame, confirming the stack grows toward lower addresses on this architecture.

### Pointer aliasing

`p_local = &local_int` inside the **same** `dump_frame` call — this is intra-frame aliasing, not cross-frame:

| Depth | `p_local` value | Matches `&local_int`? |
|---|---|---|
| 0 | `0x7ffd4b68e1d4` | ✅ identical |
| 1 | `0x7ffd4b68e1a4` | ✅ identical |
| 2 | `0x7ffd4b68e174` | ✅ identical |
| 3 | `0x7ffd4b68e144` | ✅ identical |

Writing through `*p_local` would write directly to that call's `local_int`. This pointer never escapes its frame (it is never returned or stored anywhere `main` or `walk_stack` can reach), so there is no dangling-pointer risk in this file.

### Address reuse — enter vs exit

For every depth, `dump_frame("enter", d)` and `dump_frame("exit", d)` are **two separate calls**, yet the real output shows identical addresses each time:

| Depth | enter `local_buf` | exit `local_buf` |
|---|---|---|
| 3 | `0x7ffd4b68e150` | `0x7ffd4b68e150` |
| 2 | `0x7ffd4b68e180` | `0x7ffd4b68e180` |
| 1 | `0x7ffd4b68e1b0` | `0x7ffd4b68e1b0` |
| 0 | `0x7ffd4b68e1e0` | `0x7ffd4b68e1e0` |

This is address **reuse**, not the same object persisting: the "enter" frame is fully destroyed before the recursive call, and the "exit" call later reuses that same freed stack slot. They are logically distinct objects that happen to occupy the same bytes because nothing else used that memory in between.

### Step-by-step memory map

**Step 1 — `main()` calls `walk_stack(0, 3)`**
```
Stack:
  [main frame]
  [walk_stack depth=0] depth=0 max_depth=3 marker=0 @ 0x7ffd4b68e224
```

**Step 2 — `walk_stack` depth=0 calls `dump_frame("enter", 0)`**
```
Stack:
  [main frame]
  [walk_stack depth=0]  marker=0 @ 0x7ffd4b68e224
  [dump_frame]  local_int=100 @ 0x7ffd4b68e1d4
                local_buf @ 0x7ffd4b68e1e0, local_buf[0]='A'
                p_local = 0x7ffd4b68e1d4  ← same address as local_int (alias)
```

**Step 3 — `dump_frame` returns**
```
dump_frame frame destroyed — local_int, local_buf, p_local now invalid.
walk_stack(depth=0) frame still alive — marker=0 still valid.
```

**Step 4 — recursion peaks at depth=3 (deepest point, all 4 frames alive at once)**
```
Stack (top to bottom):
  [walk_stack depth=3] marker=30 @ 0x7ffd4b68e194
  [walk_stack depth=2] marker=20 @ 0x7ffd4b68e1c4
  [walk_stack depth=1] marker=10 @ 0x7ffd4b68e1f4
  [walk_stack depth=0] marker=0  @ 0x7ffd4b68e224
  [main frame]
```

**Step 5 — unwinding begins (`3 < 3` is false, base case, no more recursion)**
```
depth=3 runs dump_frame("exit", 3) then returns → its frame popped
depth=2 resumes at its call site → marker @ 0x7ffd4b68e1c4 still 20, untouched
depth=2 runs dump_frame("exit", 2) then returns → popped
depth=1 resumes → marker @ 0x7ffd4b68e1f4 still 10, untouched
... and so on down to depth=0 → main resumes → return 0
```

Each `marker` is a **distinct stack slot per call**. Depth 2's `marker=20` is never touched by depth 3's existence or exit, even though depth 3's frame sat directly above it in memory.

---

## 2. heap_example.c

### Heap allocations (real addresses)

| Allocation | Address | Size | Freed? |
|---|---|---|---|
| `alice` struct | `0x5b3146553420` | 16 bytes (`char*` + `int`, padded) | ❌ never freed as intended — freed via `person_free_partial`, but... |
| `alice->name` | `0x5b3146553440` | 6 bytes ("Alice\0") | ❌ **leaked, never freed** |
| `bob` struct | `0x5b3146553460` | 16 bytes | ✅ freed |
| `bob->name` | `0x5b3146553480` | 4 bytes ("Bob\0") | ✅ freed |

### Chunk spacing observation

The four blocks sit exactly `0x20` (32 bytes) apart, even though `sizeof(Person)` is only 16 bytes and `"Alice\0"` is only 6 bytes:

```
0x5b3146553420  (alice struct, 16 bytes requested)
0x5b3146553440  (+0x20 = 32 bytes later)
0x5b3146553460  (+0x20)
0x5b3146553480  (+0x20)
```

This is glibc's allocator rounding every request up to its minimum chunk size (16-byte payload alignment + 8-byte size-header, minimum usable chunk of 32 bytes on 64-bit systems) — the requested size and the actual space consumed on the heap are not the same thing.

### Why free order matters

`bob` is freed correctly: `free(bob->name)` (frees `0x5b3146553480`) happens *before* `free(bob)` (frees `0x5b3146553460`). The pointer to the string is still reachable through `bob->name` at the moment it's freed.

`alice` is freed incorrectly: `person_free_partial(alice)` only calls `free(p)` on the struct at `0x5b3146553420`. The only reference to `alice->name` (`0x5b3146553440`) lived inside that struct. Once the struct is freed, that address is gone — `alice->name` is now unreachable for the rest of the program. This is a genuine memory leak, not just a dangling pointer, because nothing will ever call `free()` on it.

### Step-by-step memory map

**Step 1 — after `person_new("Alice", 30)` returns**
```
Heap:
  0x5b3146553420  Person{name: 0x5b3146553440, age: 30}   LIVE
  0x5b3146553440  "Alice\0"                                LIVE
main frame: alice = 0x5b3146553420, bob = NULL
```

**Step 2 — after `person_new("Bob", 41)` returns**
```
Heap:
  0x5b3146553420  Person{name: 0x5b3146553440, age: 30}   LIVE
  0x5b3146553440  "Alice\0"                                LIVE
  0x5b3146553460  Person{name: 0x5b3146553480, age: 41}   LIVE
  0x5b3146553480  "Bob\0"                                  LIVE
main frame: alice = 0x5b3146553420, bob = 0x5b3146553460
```

**Step 3 — `free(bob->name);` then `free(bob);`**
```
Heap:
  0x5b3146553420  Person{...}   LIVE   (alice, untouched)
  0x5b3146553440  "Alice\0"     LIVE   (alice's name, untouched)
  0x5b3146553460  Person{...}   FREED  (bob struct)
  0x5b3146553480  "Bob\0"       FREED  (bob's name — freed first, correctly)
main frame: bob = 0x5b3146553460 (dangling value, but never dereferenced again)
```

**Step 4 — `person_free_partial(alice);` → internally `free(p);`**
```
Heap:
  0x5b3146553420  Person{...}   FREED
  0x5b3146553440  "Alice\0"     LEAKED — no pointer anywhere references it anymore
main frame: alice = 0x5b3146553420 (dangling value)
```

### Memory leak analysis

`person_free_partial()` frees only the outer `Person` struct — `p->name` is a completely separate allocation and `free()` has no knowledge of struct internals, so it cannot cascade. Every call to this function leaks exactly `len + 1` bytes (6 bytes for "Alice"). Valgrind with `--leak-check=full` would report this as "definitely lost: 6 bytes in 1 blocks," pointing at the `malloc(len + 1)` call inside `person_new`.

---

## 3. aliasing_example.c

### Compiler-level detection

Compiling with the assignment's exact `-Werror` flags fails outright:
```
aliasing_example.c:45:34: error: pointer 'b' used after 'free' [-Werror=use-after-free]
aliasing_example.c:44:6:  error: pointer 'b' used after 'free' [-Werror=use-after-free]
aliasing_example.c:42:36: error: pointer 'b' used after 'free' [-Werror=use-after-free]
aliasing_example.c:40:5:  error: pointer 'b' used after 'free' [-Werror=use-after-free]
```
GCC's `-Wuse-after-free` (part of `-Wall` since GCC 12) performs static dataflow analysis: it tracks that `b = a` makes `b` an alias of `a`, sees `free(a)` on line 38, and flags every subsequent dereference of `b` as a compile-time error rather than letting it become a silent runtime bug. Removing `-Werror` (not editing the source) downgrades these to warnings and allows the binary to build.

### Real addresses from the actual run

```
a=0x61d3705c4420 b=0x61d3705c4420 a[2]=22 b[2]=22
after free(a): b=0x61d3705c4420 (dangling)
reading b[2]=1826454939
wrote b[3]=1234
```

`a` and `b` hold the **identical** address — confirmed alias, not just theoretically. After `free(a)`, reading `b[2]` returns `1826454939`, not `22`.

### Why `b[2]` is not 22 after `free()`

`free()` does not zero or clear memory — it only returns the block to the allocator's free-list bookkeeping. glibc's tcache writes a "next" pointer and a security "key" (16 bytes total on 64-bit) into the first bytes of the just-freed chunk. `b[2]` is at byte offset 8 into the block (`int` index 2 × 4 bytes), which falls inside that 16-byte metadata region — so the read returns reinterpreted allocator bookkeeping data, not the value `22` that used to be there.

### Step-by-step memory map

**Step 1 — `make_numbers(5)` returns, assigned to `a`**
```
Stack: a = 0x61d3705c4420, b = NULL
Heap:  int[5] @ 0x61d3705c4420 = {0, 11, 22, 33, 44}   LIVE
```

**Step 2 — `b = a;`**
```
Stack: a = 0x61d3705c4420
       b = 0x61d3705c4420  ← identical address, alias created
Heap:  int[5] @ 0x61d3705c4420  LIVE, two pointer variables reference it
```

**Step 3 — `a[2]` and `b[2]` both read: `22`**
```
Both resolve to the same byte offset (0x61d3705c4420 + 8) → 22, confirming aliasing.
```

**Step 4 — `free(a);`**
```
Stack: a = 0x61d3705c4420  ← dangling (value unchanged, object gone)
       b = 0x61d3705c4420  ← dangling (same)
Heap:  block @ 0x61d3705c4420  FREED — allocator overwrites bytes 0-15 with bookkeeping
```

**Step 5 — `b[2]` read (use-after-free)**
```
b[2] → 1826454939   (allocator metadata reinterpreted as int, NOT 22)
```

**Step 6 — `b[3] = 1234;` (use-after-free write)**
```
Writes into the same freed, metadata-holding region — corrupts allocator bookkeeping
for this chunk (or, if the block had already been reused by another malloc(), this
would corrupt unrelated live data instead).
```

**Step 7 — `b[3]` read back**
```
b[3] → 1234   (reads back exactly what was just written — no allocator reuse
               happened in between these two lines)
```

### Use-after-free analysis

After `free(a)`, `b` becomes dangling — it still holds `0x61d3705c4420` as a *value*, but the object at that address no longer exists as far as the allocator is concerned. `free()` operates on the memory block, never on the pointer variables that reference it; every alias remains a stale value until explicitly reassigned or nulled. Valgrind would report three separate errors here: invalid read at the `b[2]` line, invalid write at the `b[3] = 1234` line, and invalid read at the final `b[3]` printf line — all attributed to the same block freed earlier.

---

## 4. crash_example.c

### Real run output

```
crash_example: deterministic NULL dereference (segmentation fault)
  requesting n=0
Segmentation fault         ./crash_example
```

### Crash analysis

`n = 0` is hardcoded in `main`. `allocate_numbers(0)` hits `if (n <= 0) return NULL;` before `malloc` is ever called — the heap is never touched in this run. `nums` is assigned `NULL`, and nothing checks it before `nums[0] = 42;` dereferences it.

### Step-by-step memory map

**Step 1 — `main()` calls `allocate_numbers(0)`**
```
Stack: n = 0
       nums = NULL (not yet assigned)
Heap:  untouched
```

**Step 2 — `allocate_numbers` returns `NULL`**
```
n <= 0 → early return, malloc() line never reached.
Stack: nums = NULL
Heap:  untouched, no allocation exists
```

**Step 3 — `nums[0] = 42;` → NULL pointer dereference**
```
Evaluates to *(0x0 + 0) = 42
Address 0x0 is not mapped into this process's address space.
CPU/MMU raises a page fault → kernel delivers SIGSEGV → process terminates here.
```

Everything after this line is unreachable: the `printf` showing `nums[0]`, and `free(nums)`, never execute.

### Note on why address 0 causes an immediate, deterministic crash

Address `0x0` and the page around it are reserved and left unmapped by the OS as a general memory-layout convention on Linux (not something added specifically for this program). Any dereference of an uninitialized-to-zero or explicitly-NULL pointer will reliably fault the same way, every run, at the same line — which is why this crash is 100% deterministic rather than intermittent, unlike the aliasing example's use-after-free (where the outcome depends on allocator state).

---

## 5. AI Error Documentation

Two concrete cases where an earlier explanation I (the AI) gave was wrong, and how the actual runtime data corrected it.

### Error 1 — `aliasing_example.c`: predicting the value of `b[2]` after `free()`

**What I said (before the program had been run with real data):**
> "In practice this often 'works' (reads back 22) because the memory hasn't been reused yet — but it's undefined behavior."

**Why this was misleading:** I implied that reading the original value back (`22`) was the *likely* outcome after `free()`, framing corruption as an edge case. That's backwards for a modern glibc allocator: `free()` immediately writes tcache bookkeeping (a next-pointer and a security key, 16 bytes) into the start of the freed chunk — before any second `malloc()` ever happens. Since `b[2]` and `b[3]` fall inside that first 16-byte region, corruption isn't a rare possibility, it's the expected outcome on this allocator.

**Correction, based on the real run:**
```
reading b[2]=1826454939
```
The value is garbage — allocator metadata reinterpreted as an `int` — confirming that "likely still 22" was the wrong prediction. The correct statement is: any read from within the first 16 bytes of a freed tcache chunk should be expected to return allocator bookkeeping, not the pointer's original contents, even before any reuse by another `malloc()`.

### Error 2 — `crash_example.c`: overstating why address `0x0` is unmapped

**What I originally said:**
> "That address is never mapped into the process's address space, so ... this kind of bug is caught immediately by hardware" — phrased as if the unmapped null page exists *specifically* to catch this program's bug.

**Why this was wrong:** The null page being unmapped is a general-purpose OS/architecture convention that predates and has nothing to do with this specific program — it exists so that *any* NULL dereference across *any* program reliably faults instead of silently reading/writing near address zero. Framing it as a mechanism reacting to this program's bug overstates the causal relationship.

**Correction:** Address `0x0` is unmapped as a standing property of the process's virtual address space (true for every Linux process, every run, unrelated to what this code does). This program's specific bug is simply that it never checks `allocate_numbers()`'s return value for `NULL` before dereferencing it — the crash is deterministic *because* `n` is hardcoded to `0`, not because the OS designed anything around this file.

