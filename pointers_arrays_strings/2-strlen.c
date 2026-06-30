#include "main.h"
/**
 * _strlen - Write a function that returns the length of a string
 * @s : pointer of a char
 * Return: lenght of string
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
