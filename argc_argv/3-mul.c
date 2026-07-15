#include "main.h"
/**
 * main - Write a program that multiplies two numbers.
 * @argc: count of arguments
 * @argv: number of arguments
 * Return: 0 if success, 1 if fail
 */
int main(int argc, char *argv[])
{
	int i, mul = 1;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			mul *= atoi(argv[i]);
		}
	}
	printf("%d\n", mul);
	return (0);
}
