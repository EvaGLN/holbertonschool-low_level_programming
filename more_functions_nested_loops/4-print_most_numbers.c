#include <stdio.h>
/**
 * print_most_numbers - print alphabet without e and q
 * Return: Always 0
 */
void print_most_numbers(void)
{
	char num;

	for (num = '0'; num <= '9'; num++)
	{
		if (num != '2' && num != '4')
		{
		putchar(num);
		}
	}
	putchar('\n');
	return (0);
}
