#include "main.h"
#include <stdio.h>
/**
 * print_diasums - prints sum of two diagonals of a square matrix of integers
 * @a: array
 * @size: position in the array
 * Return: results
 */
void print_diagsums(int *a, int size)
{
	int i, j, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + (i * size) + i);
	}
	for (j = 0; j < size; j++)
	{
		sum2 += *(a + (j * size) + (size - 1 - j));
	}
	printf("%d, %d\n", sum1, sum2);
}
