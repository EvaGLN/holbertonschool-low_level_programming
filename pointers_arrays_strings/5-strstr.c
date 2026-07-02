#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: located substring
 * Return: pointer to begining of located substring or NULL if not
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	for (; *haystack != '\0'; haystack++)
	{
		for (i = 0; needle[i] != '\0'; i++)
		{
			if (haystack[i] != needle[i])
			{
				break;
			}
		}
		if (needle[i] == '\0')
		{
			return (haystack);
		}
	}
	return (NULL);
}
