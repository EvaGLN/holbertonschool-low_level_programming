#include "main.h"
/**
 * _strncpy - copy a string
 * @dest: destination
 * @src: source
 * @n: limit of copy
 * Return: point to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (i = 0; i < n && *src != '\0'; i++, dest++, src++)
	{
		*dest = *src;
	}
	for (; i < n; i++, dest++, src++)
	{
		*dest = '\0';
	}
	return (dest);
}

