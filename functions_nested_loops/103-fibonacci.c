#include <stdio.h>
/**
 * main - print even-value Fibonacci numbers before sum exceed 4m
 * Return: Always 0
 */
int main(void)
{
	long a, b, c, sum;

	a = 2;
	b = 4;
	sum = 0;
	for (; a <= 4000000;)
	{
		sum = sum + a;
		c = a + b;
		a = b;
		b = c;
	}
	printf("%ld\n", sum);
	return (0);
}
