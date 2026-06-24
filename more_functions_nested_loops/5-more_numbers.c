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
			_putchar(c);
		}
	_putchar('\n');
	}
}
