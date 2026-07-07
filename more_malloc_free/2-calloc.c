#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocate memory for an array, using malloc
 * @nmemb:
 * @size:
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, t;
	char *a;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	a = malloc(nmemb * size);
	if (a == NULL)
	{
		return (NULL);
	}
	t = nmemb * size;
	for (i = 0; i < t; i++)
	{
		a[i] = 0;
	}
	return (a);
}
