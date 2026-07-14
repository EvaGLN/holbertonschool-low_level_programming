#include "variadic_functions.h"
/**
 * print_all - Write a function that prints anything.
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sep = "";
	va_list arg;

	va_start(arg, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(arg, int));
				sep = ", ";
				break;
			case 'i':
				printf("%s%d", sep, va_arg(arg, int));
				sep = ", ";
				break;
			case 'f':
				printf("%s%f", sep, va_arg(arg, double));
				sep = ", ";
				break;
			case 's':
				str = va_arg(arg, char *);
				if (!str)
				{
					str = "(nil)";
				}
				printf("%s%s", sep, str);
				sep = ", ";
				break;
		}
		i++;
	}
	printf("\n");
	va_end(arg);
}
