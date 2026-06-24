#include "main.h"
/**
 * print_sign - print sign of number
 * @n: to check
 * Return: Always 0
 */
int print_sign(int n)
{
	if (n > '0')
	{
		return (1);
		_putchar('+');
	}
	else if (n = '0')
	{
		return (0);
		_putchar('0');
	}
	else
	{
		return (1);
		_putchar('-');
	}
	return (0);
}
