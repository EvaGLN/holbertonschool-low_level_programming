#include "main.h"
/**
 * print_last_digit - obvious
 * Return: last
 */
int print_last_digit(int r)
{
	int last;

	if (r < 0)
	{
		last = (r % 10) * -1;
	}
	else
	{
		last = r % 10;
	}
	_putchar(last + '0');
	return (last);
}
