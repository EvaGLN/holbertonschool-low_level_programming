#include "main.h"
/**
 * times_table - 0 to 9
 * Return: Always 0
 */
void times_table(void)
{
	int line;
	int column;
	int result;

	for (line = 0; line <= 9; line++)
	{
		for (column = 0; column <= 9; column++)
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
			else
			{
				_putchar(',');
				_putchar(' ');
				_putchar((result / 10) + '0');
				_putchar((result % 10) + '0');
			}
		}
		_putchar('\n');
	}
}
