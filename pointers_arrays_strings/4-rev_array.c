#include "main.h"
/**
 * reverse_array - reverse content of array of integers
 * @a: array
 * @n: number of array
 */
void reverse_array(int *a, int n)
{
	int begin, end, tmp;

	for (begin = 0, end = n - 1; begin < end; begin++, end--)
	{
		tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
	}
}
