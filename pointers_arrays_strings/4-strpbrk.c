#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: string
 * @accept: string containing bytes to match
 * Return: pointer to byte in s matching any byte in accept, or NULL if not
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	for (; *s; s++)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
	}
	return (NULL);
}
