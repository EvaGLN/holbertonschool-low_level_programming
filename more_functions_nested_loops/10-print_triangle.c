#include "main.h"
/**
 * print_triangle - obvious
 * @size: limit of the triangle
 */
void print_triangle(int size)
{
	int l;
	int e;
	int h;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (l = 0; l < size; l++)
		{
			for (e = 0; e < (size - l - 1); e++)
			{
				_putchar(' ');
			}
			for (h = 0; h < (l + 1); h++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
