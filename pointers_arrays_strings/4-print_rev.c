#include "main.h"
/**
 * print_rev - prints a string, in reverse, followed by a new line.
 * @s: pointer to a char
 */
void print_rev(char *s)
{
	int caract;
	int lenght;
	
	for (lenght = 0; s[lenght] != '\0'; lenght++)
	{
		for (caract = lenght - 1; caract >= 0; caract--)
		{
			_putchar(s[caract]);
		}
		_putchar('\n');
	}
}
