#include <stdio.h>
/**
 * main - print 50 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
	unsigned long a, b, sum;
	int n;

	a = 1;
	b = 2;
	printf("%lu, %lu", a, b);
	for (n = 3; n <= 98; n++)
	{
		sum = a + b;
		printf(", %lu", sum);
		a = b;
		b = sum;
	}
	printf("\n");
	return (0);
}
