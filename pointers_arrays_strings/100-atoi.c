#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: pointer to a char
 * Return: integer signed
 */
int _atoi(char *s)
{
	int n;
	unsigned int nb = 0;
	int minus = 1;
	int decode = 0;

	for (n = 0; s[n] < '0' || s[n] > '9'; n++)
	{
		if (s[n] == '-')
		{
			minus *= -1;
		}
	}
	for (n = 0; s[n] != '\0' && (decode == 0 || decode == 1); n++)
	{
		if (s[n] >= '0' && s[n] <= '9')
		{
			nb = nb * 10 + (s[n] - '0');
			decode = 1;
		}
		else if (decode == 1)
		{
			decode = 2;
		}
	}
	return (minus * nb);
}
