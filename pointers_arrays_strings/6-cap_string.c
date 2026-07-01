#include "main.h"
/**
 * cap_string - capitalize the first letter of all words
 * @s: pointer to a char
 * Return: string modified
 */
char *cap_string(char *s)
{
	int n, o;
	int decode = 0;
	char *sep = " \t\n,;.!?\"(){}";

	for (n = 0; s[n] != '\0'; n++)
	{
		if (decode == 0 && s[n] >= 'a' & s[n] <= 'z')
		{
			s[n] = s[n] - ('a' - 'A');
			decode = 1;
		}
		for (o = 0; sep[o] != '\0' o++)
		{
			if (s[n] == sep[o])
			{
				decode = 0;
			}
		}
	}
	return (s);
}
