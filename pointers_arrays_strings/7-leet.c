#include "main.h"
/**
 * leet - encode a string to L337
 * @s: string
 * Return: string changed
 */
char *leet(char *s)
{
	int i, j;
	char *caract = "aAeEoOtTlL";
	char *change = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; caract[j] != '\0'; j++)
		{
			if (s[i] == caract[j])
			{
				s[i] = change[j];
			}
		}
	}
	return (s);
}
