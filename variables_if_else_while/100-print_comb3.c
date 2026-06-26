#include <stdio>
/**
 * main - 
 */
int main(void)
{
	int d;
	int u;

	if (d < u)
	{
		for (d = 0; d < 10; d++)
		{
			for (u = 0; u < 10; u++)
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
