#include <stdio.h>
/**
 * main - print hexa miscule
 * Return: Always 0
 */
int main(void)
{
	int number, minuscule;

	for (number = '0'; number <= '9'; number++)
	{
		putchar(number);
	}
	for (minuscule = 'a'; minuscule <= 'f'; minuscule++)
	{
		putchar(minuscule);
	}
	putchar('\n');
	return (0);
}
