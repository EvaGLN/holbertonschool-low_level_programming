#include "main.h"
/**
 * _memset - fills memory with constant byte
 * @s:memory area
 * @b:constant byte
 * @n:bytes numbers
 * Return: point to the memore area
 */
char *_memset(char *s, char b, unsigned int n)
{
	for (n = 0; *s <= n; n++, s++)
	{
		*s = b;
	}
	return (s);
}
