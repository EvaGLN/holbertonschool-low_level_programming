#include "main.h"
/**
 * factorial - Write a function that returns the factorial of a given number.
 * @n: number
 * Return: if n lower than 0, function should return -1 to indicate error
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
