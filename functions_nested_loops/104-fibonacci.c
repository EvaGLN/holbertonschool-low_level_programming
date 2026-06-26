#include <stdio.h>
#define BASE 1000000000000000000UL
/**
 * main - print 50 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
	unsigned long a_hi, a_lo, b_hi, b_lo, sum_lo, n_hi, n_lo, carry;
	int n;

	a_hi = 0;
	a_lo = 1;
	b_hi = 0;
	b_lo = 2;
	printf("%lu, %lu", a_lo, b_lo);
	for (n = 3; n <= 98; n++)
	{
		sum_lo = a_lo + b_lo;
		carry = sum_lo / BASE;
		n_lo = sum_lo % BASE;
		n_hi = a_hi + b_hi + carry;
		if (n_hi == 0)
		{
			printf(", %lu", n_lo);
		}
		else
		{
			printf(", %lu%018lu", n_hi, n_lo);
		}
		a_hi = b_hi;
		a_lo = b_lo;
		b_hi = n_hi;
		b_lo = n_lo;
	}
	printf("\n");
	return (0);
}
