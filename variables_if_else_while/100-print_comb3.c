#include <stdio.h>
/**
 * main - print smallest combinations of 2 digits except doubles
 * Return: Always 0
 */
int main(void)
{
	int d, u;

	for (d = 0; d < 10; d++)
	{
		for (u = d + 1; u < 10; u++)
		{
			putchar(d + '0');
			putchar(u + '0');
			if (d != 8 && u != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
