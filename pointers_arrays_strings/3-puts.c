#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: 
 */
void _puts(char *str)
{
	int caract;

	for (caract = 0; str[caract] != '\0'; caract++)
	{
		_putchar(caract + '0');
	}
	_putchar('\n');
}
