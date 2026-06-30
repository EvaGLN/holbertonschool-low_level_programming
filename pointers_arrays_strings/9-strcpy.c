#include "main.h"
/**
 * _strcpy - copy str pointed to by src include term \0 to buffer pointed to by dest
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
