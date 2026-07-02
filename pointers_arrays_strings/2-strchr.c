#include "main.h"
/**
 * _strchr - locates a char is a string
 * @s: string
 * @c: searched char
 * Return: first occurence of char in string or null
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s[i]);
		}
	}
	if (c == '\0')
	{
		return (s[i]);
	}
	return (s);
}
