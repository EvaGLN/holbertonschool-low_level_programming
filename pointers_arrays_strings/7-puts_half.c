#include "main.h"
/**
 * puts_half - prints half a string followed by a new line
 * @str: pointer to a char
 */
void puts-half(char *str)
{
	int caract, half;

	for (caract = 0; str[caract] != '\0'; caract++)
	{
	}
	half = caract / 2;
	if (caract % 2 != 0)
	{
		half++;
	}
	for (caract = half; str[caract] != '\0'; caract++)
	{
		_putchar(str[caract]);
	}
	_putchar('\n');
}
