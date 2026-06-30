#include "main.h"
/**
 * puts2 - prints 1/2 character followed by new line
 * @str - pointer to a char
 */
void puts2(char *str)
{
	int caract;

	for (caract = 0; str[caract] != '\0'; caract++)
	{
		if (caract % 2 == 0)
		{
			_putchar(str[caract]);
		}
	}
	_putchar('\n');
}
