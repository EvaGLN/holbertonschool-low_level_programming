#include <stdio.h>
/**
 * main - print 1 to 10
 * Return: Always 0
 */
int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
	{
		putchar("%d", number);
	}
	putchar("\n");
	return (0);
}
