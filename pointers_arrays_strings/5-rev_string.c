#include "main.h"
/** rev_string - reverse a string
 * @s: pointer to a char
 */
void rev_string(char *s)
{
	int a, *a, b, *b, lenght, tmp;
	
	for (lenght = 0; s[lenght] != '\0'; lenght++)
	{
	}
	for (a = 0, b = lenght - 1; a < b; a++, b--)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
