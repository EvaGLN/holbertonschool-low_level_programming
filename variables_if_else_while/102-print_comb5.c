#include <stdio.h>
/**
 * main - print twice spaced smallest combinations of 2 digits except doubles
 * Return: Always 0
 */
int main(void)
{
	int m, c, d, u;

	for (m = 0; m < 10; m++)
	{
		for (c = 0; c < 10; c++)
		{
			for (d = 0; d < 10; d++)
			{
				for(u = 0; u < 10; u++)
				{
					if (d > m || (d == m && u> c))
					{
						putchar(m + '0');
						putchar(c + '0');
						putchar(' ');
						putchar(d + '0');
						putchar(u + '0');
						if (m != 9 || c != 8 || d != 9 || u != 9)
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
