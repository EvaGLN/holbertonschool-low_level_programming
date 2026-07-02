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
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (*haystack == needle[j])
			{
				break;
			}
		}
		return (haystak);
	}
	return (NULL);
}
