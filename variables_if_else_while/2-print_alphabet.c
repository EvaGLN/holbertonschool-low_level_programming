#include <stdio.h>
/**
 * main - print alphabet
 * Return: Always 0
 */
int main(void)
{
	char minuscule = 'a';

	while (minuscule <= 'z')
	{
		putchar(minuscule);
		minuscule++;
	}
	putchar('\n');
	return (0);
}
