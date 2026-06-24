#include "main.h"
/**
 * more_numbers - 10 times
 */
void more_numbers(void)
{
	char c;
	int i;

	for (i = 1; i <= 10; i++)
	{
		for (c = '0'; c <= '14'; c++)
		{
			if (c <=9)
			{
				_putchar(c);
			}
			else
			{
				_putchar(c / 10);
				_putchar(c % 10);
			}
		}
	_putchar('\n');
	}
}
