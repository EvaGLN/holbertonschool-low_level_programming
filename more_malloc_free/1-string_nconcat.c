#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenate 2 strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to newly allocated space or NULL if fail
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, j, k;
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
	if (n >= j)
	{
		n = j;
	}
	a = malloc(i + n + 1);
	if (a == NULL)
	{
		return (NULL);
	}
	for (k = 0; k < i; k++)
	{
		a[k] = s1[k];
	}
	for (k = 0; k < n; k++)
	{
		a[i + k] = s2[k];
	}
	a[i + n] = '\0';
	return (a);
}
