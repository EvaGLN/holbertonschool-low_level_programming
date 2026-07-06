#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenate 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to newly allocated space or NULL if fail
 */
char *str_concat(char *s1, char *s2)
{
	int i, j;
	char *a;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (i = 0; s1[i]; i++)
	{
	}
	for (j = 0; s2[j]; j++)
	{
	}
	a = malloc((i + j + 1) * sizeof(char));
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; s1[i]; i++)
	{
		a[i] = s1[i];
	}
	for (j = 0; s2[j]; i++, j++)
	{
		a[i] = s2[j];
	}
	a[i] = '\0';
	return (a);
}
