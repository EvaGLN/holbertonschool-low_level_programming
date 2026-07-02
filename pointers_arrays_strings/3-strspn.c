#include "main.h"
/**
 * _strspn - get the lenght of a prefix substring
 * @s: string
 * @accept: string containing char to match
 * Return: number of bytes in the initial segment of s
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, count;

	for(count = 0; *s; s++)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				count++;
			}
			else
			{
				break;
			}
		}
	}
	return (count);
}
