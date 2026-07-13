#include "function_pointers.h"
/**
 * print_name - Write a function that prints a name.
 * @name: name to print
 * @f: pointer to the function
 */
void print_name(char *name, void (*f)(char *))
{
	printf("%d", f(name));
}
