#include "main.h"
/**
 * print_last_digit - obvious
 * Return: Always 0
 */
int print_last_digit(int r)
{
	char last;
	last = (r % 10);
	{
		_putchar(last);
		return(last);
	}
	return (0);
}
