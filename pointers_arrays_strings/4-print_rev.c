#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s: pointer to a char
 */
void print_rev(char *s)
{
	int caract = '\0';

	for (caract = caract--; str[caract] >= 0; caract--)
	{
		_putchar(str[caract]);
	}
	_putchar('\n');
}
