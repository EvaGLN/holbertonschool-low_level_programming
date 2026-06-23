#include <stdio.h>
/**
 * main - print alphabet without e and q
 * Return: Always 0
 */
int main(void)
{
	char minuscule;

	for (minuscule = 'a'; minuscule <= 'z'; minuscule++)
	{
		if (minuscule != 'e' && minuscule != 'q')
		{
		putchar(minuscule);
		}
	}
	putchar('\n');
	return (0);
}
