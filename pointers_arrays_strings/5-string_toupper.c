#include "main.h"
/**
 * string_toupper - convert lowercase to uppercase
 * @arr: string to convert
 * Return: new value
 */
char *string_toupper(char *arr)
{
	int i;

	for (i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = arr[i] - ('a' - 'A');
		}
	}
	return (arr);
}
