#include <stdio.h>
/**
 * main - print alphabet
 * Return: Always 0
 */
int main(void)
{
	char minuscule = 'a';
	char majuscule = 'A';

	while (minuscule <= 'z')
	{
		putchar(minuscule);
		minuscule++;
	}
	while (majuscule <= 'Z')
	{
		putchar(majuscule);
		majuscule++;
	}
	putchar('\n');
	return (0);
}
