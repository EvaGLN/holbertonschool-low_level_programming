#include "main.h"
/**
 * print_times_table - time tables until square no more than 15
 * @n: to multiply
 */
void print_times_table(int n)
{
	int line;
	int column;
	int result;

	if (n < 0 || n > 15)
	{
		return;
	}
	for (line = 0; line <= n; line++)
	{
		for (column = 0; column <= n; column++)
		{
			result = (line * column);
			if (column  == 0)
			{
				_putchar(result + '0');
			}
			else if (result <= 9)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(result + '0');
			}
			else if (result <= 99)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
			else
			{
				_putchar(',');
				_putchar((result / 100) + '0');
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
