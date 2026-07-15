#include "main.h"
/**
 * main - Write a program that prints the number of arguments passed into it.
 * @argc: count of arguments
 * @argv: array of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}
