#include "main.h"
#include <stdlib.h>
/**
 * _strdup - return a pointer to newly alloc space in memory containing
 * a copy of string given as parameter
 * @str: string to copy
 * Return: NULL if str NULL
 */
char *_strdup(char *str)
{
	int i;
	char *a;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
	}
	a = malloc((i + 1) * sizeof(char));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		a[i] = str[i];
	}
	a[i] = '\0';
	return (a);
}
