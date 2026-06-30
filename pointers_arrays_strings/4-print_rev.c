#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s: pointer to a char
 */
void print_rev(char *s)
{
	int caract;

	for (caract = s['\0']--; s >= 0; caract--)
	{
		_putchar(s[caract]);
	}
	_putchar('\n');
}
