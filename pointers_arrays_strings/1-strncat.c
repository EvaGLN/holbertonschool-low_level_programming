#include "main.h"
/**
 * _strncat - concatenate two strings could be limited by n
 * @dest: begining of the string
 * @src: end of the string
 * @n: limit of copy
 * Return: point to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr;
	int i;

	for (ptr = dest; *ptr != '\0'; ptr++)
	{
	}
	for (i = 0; i < n && *src != '\0'; i++, ptr++, src++)
	{
		*ptr = *src;
	}
	*ptr = '\0';
	return (dest);
}
