#include <stdio.h>
/**
 * main - print even-value Fibonacci numbers before sum exceed 4m
 * Return: Always 0
 */
int main(void)
{
	long a, b, sum;

	a = 2;
	b = 4;
	printf("%ld, %ld", a, b);
	for (; sum <= 4000000;)
	{
		sum = a + b;
		printf(", %ld", sum);
		a = b;
		b = sum;
	}
	printf("\n");
	return (0);
}
