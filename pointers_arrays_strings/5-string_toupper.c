#include "main"
/**
 * string_toupper - convert lowercase to uppercase
 * Return: Always 0
 */
char *string_toupper(char *arr)
{
	int i;


	for (i = 0; *arr != '\0'; i++)
	{
		if (*arr >= 'a' && *arr <= 'z')
		{
			*str = *str -('a' - 'A');
		}
	}
	return (*str);
}
