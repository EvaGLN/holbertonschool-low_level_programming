#include <stdio.h>
/**
 * main - print 50 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
	int a, b, n, sum;

	a = 1;
	b = 2;
	printf("%d, %d", a, b);
	for (n = 2; i <=49; n++)
	{
		sum = a + b;
		printf(", %d", sum);
		a = b;
		b = tmp;
	}
	printf("\n");
	return (0);
}
