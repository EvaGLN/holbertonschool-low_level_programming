#include "main.h"
/**
 * print_number - prints an integer
 * @n: the integer
 */
void print_number(int n)
{
	int temp = n, count = 0, divisor = 1, digit;

	if (n < 0)
	{
		_putchar('-');
	}
	do
	{
		temp = temp / 10;
		count++;
	}
	while (temp != 0);
	for (;count > 1;)
	{
		divisor = divisor * 10;
		count--;
	}
	for (;divisor >= 1;)
	{
		digit = (n / divisor) % 10;
		if (digit < 0)
			digit = -digit;
		_putchar(digit + '0');
		divisor = divisor / 10;
	}
}
