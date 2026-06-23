
#include <stdio.h>
/**
 * main - print 0 to 9 with coma and space
 * Return: Always 0
 */
int main(void)
{
	int number;

	for (number = '0'; number <= '9'; number++)
	{
		putchar(number);
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}
