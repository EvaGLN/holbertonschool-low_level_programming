#include "main.h"
#include <stdlib.h>
/**
 * array_range - create array of int
 * @min: start
 * @max: end
 * Return: pointer to new array
 */
int *array_range(int min, int max)
{
	int i, size, *a;

	if (min > max)
	{
		return (NULL);
	}
	size = max - min + 1;
	a = malloc(size * sizeof(int));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		a[i] = min + i;
	}
	return (a);
}
