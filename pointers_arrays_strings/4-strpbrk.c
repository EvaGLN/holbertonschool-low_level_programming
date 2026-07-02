#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: string
 * @a: char to match
 * Return: pointer to byte in s matching any byte in accept, or NULL if not
 */
char *_strpbrk(char *s, char *accept)
{
	for (; *s; s++)
	{
		for (;*accept; accept++)
		{
			if (*s == *accept)
			{
				return (s);
			}
		}
	}
	return (NULL);
}
