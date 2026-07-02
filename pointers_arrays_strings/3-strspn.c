#include "main.h"
/**
 * _strspn - get the lenght of a prefix substring
 * @s: string
 * @accept: char to match
 * Return: max consecutive bytes in s matching accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, count;

	for(count = 0; *s; s++)
	{
		for (i = 0; accept[i]; i++, count++)
		{
			if (*s == accept[i])
			{
				break;
			}
		}
		if (accept[i] == '\0')
		{
			break;
		}
	}
	return (count);
}
