#include "main.h"
#include <stdlib.h>
/**
 * create_array - create an array of chars and init with specific char
 * @size:
 * @c:
 * Return: pointer to the array, NULL if size 0 or NULL if fails
 */
char *create_array(unsigned int size, char c)
{
	unisgned int i;
	char *a;

	if (size == 0)
	{
		return (NULL);
	}
	a = (char *) malloc(size * sizeof(char));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		a[i] = c;
	}
	return (a);
}
