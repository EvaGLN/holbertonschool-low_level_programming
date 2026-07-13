#include "function_pointers.h"
/**
 * int_index - Write a function that searches for an integer.
 * @array: array
 * @size: size of the array
 * @cmp: pointer to the function
 * Return: index of 1st element for which cmp function != return 0
 * If no element matches, return -1 and If size <= 0, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || size <= 0 || cmp == NULL)
	{
		return (-1);
	}
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}
	return (-1);
}
