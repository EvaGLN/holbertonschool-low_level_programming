#include "main.h"
/**
 * print_last_digit - obvious
 * Return: Always 0
 */
int print_last_digit(int r)
{
	int last;

	last = r % 10;
	{
		_putchar(last + '0');
		return(last);
	}
	return (0);
}
