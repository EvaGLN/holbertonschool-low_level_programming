#include "main.h"
/**
 * print_diagonal - draw diagonal
 * @n: number of backslash
 */
void print_diagonal(int n)
{
	int o;
	int p;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (o = 1; o <= n; o++)
		{
			for (p = 1; p < o; p++)
			{
				_putchar(' ');
			}
			_putchar('\\');
			_putchar('\n');
		}
	}
}
