#include "3-calc.h"
/**
 * main - Write a program that performs simple operations.
 * @argc: count of arguments
 * @argv: array of arguments
 * Return: 98, 99, 100 for errors or 0 if success
 */
int main(int argc, char *argv[])
{
	char *op;
	int divider;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	op = argv[2];
	if (get_op_func(op) == NULL)
	{
		printf("Error\n");
		return (99);
	}
	divider = atoi(argv[3]);
	if ((strcmp(op == "/") == 0 || strcmp(op == "%") == 0) && divider == 0)
	{
		printf("Error\n");
		return (100);
	}
	printf("%d\n", get_op_func(op)(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
