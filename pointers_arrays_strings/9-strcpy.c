#include "main.h"
/**
 * _strcpy - copy str from src include term \0 to buffer dest
 * @dest: destination buffer
 * @src: source of the string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int caract;

	for (caract = 0; src[caract] != '\0'; caract++)
	{
		dest[caract] = src[caract];
	}
	dest[caract] = '\0';
	return (dest);
}
