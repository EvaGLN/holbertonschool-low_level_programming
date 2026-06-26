#include <stdio.h>
/**
 * main - print smallest combinations of 2 digits except doubles
 * Return: Always 0
 */
int main(void)
{
	int d;
	int u;

	for (d = 0; d < 10; d++)
	{
		for (u = 0; u < 10; u++)
		{
			if (d != u)
			{
				putchar(d + '0');
				putchar(u + '0');
				if (d < 8 && u < 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
			putchar('\n');
		}
	}
}
