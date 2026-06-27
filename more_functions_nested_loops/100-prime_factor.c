#include <stdio.h>
/**
* main - prints the largest prime factor
* Return: Always 0
*/
int main(void)
{
	unsigned long limit, attempt, largest;
	
	limit = 612852475143UL;
	largest = 1;
	for (attempt = 2; attempt <= limit; attempt++)
	{
		for (; limit % attempt == 0;)
		{
			largest = attempt;
			limit = limit / attempt;
		}
	}
	if (limit > 1)
	{
		largest = limit;
	}
	printf("%lu\n", largest);
	return (0);
}
