#include "main.h"
/**
 * print_square - obvious
 * @size: size of the square
 */
void print_square(int size)
{
	int x;
	int y;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (y = 1; y <= size; y++)
		{
			for (x = 1; x <= y; x++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
