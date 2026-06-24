#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - point de comparaison
 * @n: point de départ
 */
void print_to_98(int n)
{
	if (n <= 98)
	{
		for (;n <= 98; n++)
		{
			if (n < 98)
			{
				printf("%d, ", n);
			}
			else
			{
				printf("%d\n", n);
			}
		}
	}
	else
	{
		for (;n >= 98; n--)
		{
			if (n > 98)
			{
				printf("%d, ", n);
			}
			else
			{
				printf("%d\n", n);
			}
		}
	}
}
