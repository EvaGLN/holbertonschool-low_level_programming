#include "main.h"
/**
 * _sqrt_finder - find square root of number
 * if it exists
 * @n: base
 * @i: tester
 * Return: natural square root or -1 if number doesn't have one
 */
int _sqrt_finder(int n, int i)
{
	if (i * i > n)
		return (-1);
	else if (i * i == n)
		return (i);
	else
		return (_sqrt_finder(n, i + 1));
}
/**
 * _sqrt_recursion - Write a function that returns
 * the natural square root of a number.
 * @n: number
 * Return: natural square root or -1 if number doesn't have one
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_finder(n, 0));
}
