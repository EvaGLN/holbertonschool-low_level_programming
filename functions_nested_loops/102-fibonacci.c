#include <stdio.h>
/**
 * main - print 50 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
	long a, b, sum;
	int n;

	a = 1;
	b = 2;
	printf("%ld, %ld", a, b);
	for (n = 2; n <=49; n++)
	{
		sum = a + b;
		printf(", %ld", sum);
		a = b;
		b = sum;
	}
	printf("\n");
	return (0);
}
