#include <stdio.h>
/**
 * main - print smallest combinations of 2 digits except doubles
 * Return: Always 0
 */
int main(void)
{
	int c, d, u;

	for (c = 0; c < 10; c++)
	{
		for (d = c + 1; d < 10; d++)
		{
			for (u = d + 1; u < 10; u++)
			{
				putchar(c + '0');
				putchar(d + '0');
				putchar(u + '0');
				if (c != 7 || d != 8 || u != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
