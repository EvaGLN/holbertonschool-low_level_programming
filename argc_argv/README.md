<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# C - argc, argv

## Table of Contents :

  - [0. It ain't what they call you, it's what you answer to](#subparagraph0)
  - [1. Silence is argument carried out by other means](#subparagraph1)
  - [2. The best argument against democracy is a five-minute conversation with the average voter](#subparagraph2)
  - [3. Neither irony nor sarcasm is argument](#subparagraph3)
  - [4. To infinity and beyond](#subparagraph4)
  - [5. Minimal Number of Coins for Change](#subparagraph5)
## Resources

**Read or watch**:

- [Arguments to main](/rltoken/ro9HSskzyAhNpzdcVhdVWw) 
- [argc and argv](/rltoken/zjdRHZTL-ImDCnGuMfHYfA) 
- [What does argc and argv mean?](/rltoken/RT0y1HPM-AChT_JQedpdaA) 
- [how to compile with unused variables](/rltoken/GvQNF9qKoUuY1t0U1AsetA) 

## Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](/rltoken/mixi0RLDGmKIaS1nqcn0xg), __without the help of Google__:

### General

- How to use arguments passed to your program
- What are two prototypes of `main` that you know of, and in which case do you use one or the other
- How to use `__attribute__((unused))` or `(void)` to compile functions with unused variables or parameters

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 functions per file
- The prototypes of all your functions and the prototype of the function `_putchar` should be included in your header file called `main.h`
- Don't forget to push your header file
- You are allowed to use the standard library


## Task
### 0. It ain't what they call you, it's what you answer to <a name='subparagraph0'></a>

Write a program that prints its name, followed by a new line.

* If you rename the program, it will print the new name, without having to compile it again
* You should not remove the path before the name of the program

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-whatsmyname.c -o mynameis
julien@ubuntu:~/argc, argv$ ./mynameis 
./mynameis
julien@ubuntu:~/argc, argv$ mv mynameis mynewnameis
julien@ubuntu:~/argc, argv$ ./mynewnameis 
./mynewnameis
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `0-whatsmyname.c`

---

### 1. Silence is argument carried out by other means <a name='subparagraph1'></a>

Write a program that prints the number of arguments passed into it.

* Your program should print a number, followed by a new line

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-args.c -o nargs
julien@ubuntu:~/argc, argv$ ./nargs 
0
julien@ubuntu:~/argc, argv$ ./nargs hello
1
julien@ubuntu:~/argc, argv$ ./nargs "hello, world"
1
julien@ubuntu:~/argc, argv$ ./nargs hello, world
2
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `1-args.c`

---

### 2. The best argument against democracy is a five-minute conversation with the average voter <a name='subparagraph2'></a>

Write a program that prints all arguments it receives.

* All arguments should be printed, including the first one
* Only print one argument per line, ending with a new line

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-args.c -o args
julien@ubuntu:~/argc, argv$ ./args 
./args
julien@ubuntu:~/argc, argv$ ./args You can do anything, but not everything.
./args
You
can
do
anything,
but
not
everything.
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `2-args.c`

---

### 3. Neither irony nor sarcasm is argument <a name='subparagraph3'></a>

Write a program that multiplies two numbers.

* Your program should print the result of the multiplication, followed by a new line
* You can assume that the two numbers and result of the multiplication can be stored in an integer
* If the program does not receive two arguments, your program should print `Error`, followed by a new line, and return `1`

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-mul.c -o mul
julien@ubuntu:~/argc, argv$ ./mul 2 3
6
julien@ubuntu:~/argc, argv$ ./mul 2 -3
-6
julien@ubuntu:~/argc, argv$ ./mul 2 0
0
julien@ubuntu:~/argc, argv$ ./mul 245 3245342
795108790
julien@ubuntu:~/argc, argv$ ./mul
Error
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `3-mul.c`

---

### 4. To infinity and beyond <a name='subparagraph4'></a>

Write a program that adds positive numbers.

* Print the result, followed by a new line
* If no number is passed to the program, print `0`, followed by a new line
* If one of the number contains symbols that are not digits, print `Error`, followed by a new line, and return `1`
* You can assume that numbers and the addition of all the numbers can be stored in an `int`

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-add.c -o add
julien@ubuntu:~/argc, argv$ ./add 1 1
2
julien@ubuntu:~/argc, argv$ ./add 1 10 100 1000
1111
julien@ubuntu:~/argc, argv$ ./add 1 2 3 e 4 5
Error
julien@ubuntu:~/argc, argv$ ./add
0
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `4-add.c`

---

### 5. Minimal Number of Coins for Change <a name='subparagraph5'></a>

Write a program that prints the minimum number of coins to make change for an amount of money.

* Usage: `./change cents`
* where `cents` is the amount of cents you need to give back
* if the number of arguments passed to your program is not exactly `1`, print `Error`, followed by a new line, and return `1`
* you should use `atoi` to parse the parameter passed to your program
* If the number passed as the argument is negative, print `0`, followed by a new line
* You can use an unlimited number of coins of values 25, 10, 5, 2, and 1 cent

```ruby
julien@ubuntu:~/argc, argv$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-change.c -o change
julien@ubuntu:~/argc, argv$ ./change 
Error
julien@ubuntu:~/argc, argv$ ./change 10
1
julien@ubuntu:~/argc, argv$ ./change 100
4
julien@ubuntu:~/argc, argv$ ./change 101
5
julien@ubuntu:~/argc, argv$ ./change 13
3
julien@ubuntu:~/argc, argv$
```

**Repo:**

* GitHub repository: `holbertonschool-low_level_programming`
* Directory: `argc_argv`
* File: `100-change.c`

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
