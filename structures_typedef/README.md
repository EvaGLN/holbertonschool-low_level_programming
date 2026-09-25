<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# C - Structures, typedef

## Table of Contents :

  - [0. Poppy](#subparagraph0)
  - [1. A dog is the only thing on earth that loves you more than you love yourself](#subparagraph1)
  - [2. A dog will teach you unconditional love. If you can have that in your life, things won't be too bad](#subparagraph2)
  - [3. Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read](#subparagraph3)
  - [4. A door is what a dog is perpetually on the wrong side of](#subparagraph4)
  - [5. How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg](#subparagraph5)
## Resources

**Read or watch**:

- [0x0d. Structures.pdf](/rltoken/8TS6dWhiTS4-qstKmfl_Rw)
- [struct (C programming language)](/rltoken/VujS8Eo0cgoOhd1wpZCSwg) 
- [Documentation: structures](/rltoken/d2uohXRWLbqykxIrbJawpg) 
- [0x0d. Typedef and structures.pdf](/rltoken/haWQ15L2jOBBhM_AK97kww)
- [typedef](/rltoken/6TX-aFGQs5sAtdtyXBnjyQ) 
- **Programming in C** by Stephen Kochan - *Chapter 8, Working with Structures p163-189*
- [The Lost Art of C Structure Packing](/rltoken/qxIHARCFIPU4IGX12WVa0g) (*Advanced - not mandatory*)

## Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](/rltoken/jwBnpES7B-FM71phhXfT2Q), __without the help of Google__:

### General

- What are structures, when, why and how to use them
- How to use `typedef`

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- The only C standard library functions allowed are `printf`, `malloc`, `free` and `exit`. 
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- Don't forget to push your header file
- All your header files should be include guarded


## Task
### 0. Poppy <a name='subparagraph0'></a>

Define a new type `struct dog` with the following elements:

* `name`, type = `char *`
* `age`, type = `float`
* `owner`, type = `char *`

```cpp
julien@ubuntu:~/0x0d. structures, typedef$ cat 0-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c -o a
julien@ubuntu:~/0x0d. structures, typedef$ ./a 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `dog.h`

---

### 1. A dog is the only thing on earth that loves you more than you love yourself <a name='subparagraph1'></a>

Write a function that initialize a variable of type `struct dog`

* Prototype: `void init_dog(struct dog *d, char *name, float age, char *owner);`

```cpp
julien@ubuntu:~/0x0d. structures, typedef$ cat 1-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-init_dog.c -o b
julien@ubuntu:~/0x0d. structures, typedef$ ./b 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `1-init_dog.c`

---

### 2. A dog will teach you unconditional love. If you can have that in your life, things won't be too bad <a name='subparagraph2'></a>

Write a function that prints a `struct dog`

* Prototype: `void print_dog(struct dog *d);`
* Format: see example bellow
* You are allowed to use the standard library
* If an element of `d` is `NULL`, print `(nil)` instead of this element. (if `name` is `NULL`, print `Name: (nil)`)
* If `d` is `NULL` print nothing.

```cpp
julien@ubuntu:~/0x0d. structures, typedef$ cat 2-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 2-print_dog.c -o c
julien@ubuntu:~/0x0d. structures, typedef$ ./c 
Name: Poppy
Age: 3.500000
Owner: Bob
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `2-print_dog.c`

---

### 3. Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read <a name='subparagraph3'></a>

Define a new type `dog_t` as a new name for the type `struct dog`.

```cpp
julien@ubuntu:~/0x0d. structures, typedef$ cat 3-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c -o d
julien@ubuntu:~/0x0d. structures, typedef$ ./d 
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `dog.h`

---

### 4. A door is what a dog is perpetually on the wrong side of <a name='subparagraph4'></a>

Write a function that creates a new dog.

* Prototype: `dog_t *new_dog(char *name, float age, char *owner);`
* You have to store a copy of `name` and `owner`
* Return `NULL` if the function fails

```cpp
julien@ubuntu:~/0x0d. structures, typedef$ cat 4-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 4-new_dog.c -o e
julien@ubuntu:~/0x0d. structures, typedef$ ./e
My name is Poppy, and I am 3.5 :) - Woof!
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `4-new_dog.c`

---

### 5. How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg <a name='subparagraph5'></a>

Write a function that frees dogs.

* Prototype: `void free_dog(dog_t *d);`

```swift
julien@ubuntu:~/0x0d. structures, typedef$ cat 5-main.c
#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    free_dog(my_dog);
    return (0);
}
julien@ubuntu:~/0x0d. structures, typedef$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f
julien@ubuntu:~/0x0d. structures, typedef$ valgrind ./f
==22840== Memcheck, a memory error detector
==22840== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==22840== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==22840== Command: ./f
==22840== 
My name is Poppy, and I am 3.5 :) - Woof!
==22840== 
==22840== HEAP SUMMARY:
==22840==     in use at exit: 0 bytes in 0 blocks
==22840==   total heap usage: 4 allocs, 4 frees, 1,059 bytes allocated
==22840== 
==22840== All heap blocks were freed -- no leaks are possible
==22840== 
==22840== For counts of detected and suppressed errors, rerun with: -v
==22840== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
julien@ubuntu:~/0x0d. structures, typedef$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `structures_typedef`
* File: `5-free_dog.c`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
