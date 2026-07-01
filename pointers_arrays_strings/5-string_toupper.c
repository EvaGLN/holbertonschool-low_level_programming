#include "main.h"
/**
 * string_toupper - convert lowercase to uppercase
 * Return: new value
 */
char *string_toupper(char *arr)
{
	int i;


	for (i = 0; *arr != '\0'; i++)
	{
		if (*arr >= 'a' && *arr <= 'z')
		{
			*arr = *arr -('a' - 'A');
		}
	}
	return (*arr);
}
