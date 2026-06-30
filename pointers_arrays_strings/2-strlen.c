#include "main.h"
/**
 * _strlen - return lenght of a string
 * @s: pointer to a char
 * Return: lenght of the string
 */
int _strlen(char *s)
{
	int lenght = 0;

	while (s[lenght] != '\0')
	{
		lenght++;
	}
	return (lenght);
}
