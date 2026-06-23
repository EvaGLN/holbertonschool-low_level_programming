#include <stdio.h>
/**
 * main - print alphabet in reverse
 * Return: Always 0
 */
int main(void)
{
	char minuscule;

	for (minuscule = 'z'; minuscule >= 'a'; minuscule--)
	{
		putchar(minuscule);
	}
	putchar('\n');
	return (0);
}
