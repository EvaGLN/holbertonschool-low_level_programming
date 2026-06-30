#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: 
 */
void _puts(char *str)
{
	for (int caract = 0; str[caract] != '\0'; caract++)
	{
		_putchar(caract);
	}
	_putchar('\n');
}
