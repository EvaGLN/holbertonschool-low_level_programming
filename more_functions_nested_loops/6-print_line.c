#include "main.h"
/**
 * print_line - draw a straight line
 * @n: distance
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (; n > 0; n--)
		{
			_putchar('_');
		}
		_putchar('\n');
	}

}
