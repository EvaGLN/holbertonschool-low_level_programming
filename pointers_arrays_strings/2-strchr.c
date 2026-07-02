#include "main.h"
#include <stddef.h>
/**
 * _strchr - locates a char is a string
 * @s: string
 * @c: searched char
 * Return: first occurence of char in string or null
 */
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
