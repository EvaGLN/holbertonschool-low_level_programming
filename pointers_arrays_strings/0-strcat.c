#include "main.h"
/**
 * _strcat - concatenate two strings
 * @dest: begining of the string
 * @src: end of the string
 * Return: point to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *ptr;

	for (ptr = dest; *ptr != '\0'; ptr++)
	{
	}
	for (; *src != '\0'; ptr++, src++)
	{
		*ptr = *src;
	}
	*ptr = '\0';
	return (dest);
}
