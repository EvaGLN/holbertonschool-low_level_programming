#include "main.h"
/**
 * is_prime_finder - find if number is prime
 * @n: base
 * @i: tester
 * Return: 1 if number is prime number and 0 otherwise
 */
int is_prime_finder(int n, int i)
{
	if (i > n / i)
		return (1);
	else if (n % i == 0)
		return (0);
	else
		return (is_prime_finder(n, i + 1));
}
/**
 * is_prime_number - Write a function that returns 1 if
 * the input integer is a prime number, otherwise return 0.
 * @n: base
 * Return: 1 if number is prime number and 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (is_prime_finder(n, 2));
}
