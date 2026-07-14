#include "variadic_functions.h"
/**
 * print_numbers - Write a function that prints numbers, followed by a new line.
 * @separator: string to be printed between numbers
 * @n: count of arguments
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list arg;

	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(arg, int));
		if (separator != NULL && i < n-1)
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(arg);
}
