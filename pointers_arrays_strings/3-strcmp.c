#include "main.h"
/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: result of comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *s1 == *s2 && *s1 != '\0' && *s2 != '\0'; i++, s1++, s2++)
	{
	}
	return (s1 - s2);
}
