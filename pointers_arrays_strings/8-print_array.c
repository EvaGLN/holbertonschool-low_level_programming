#include <stdio.h>
#include "main.h"
/**
 * print_array - prints n elements of an array of int followed by a new line
 * @a: the array
 * @n: the number of elements of the array
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i <= n; i++)
	{
		if (i < n)
		{
			printf("%d, ", a[i]);
		}
		else
		{
			printf("%d", a[i]);
		}
	}
	printf("\n");
}
