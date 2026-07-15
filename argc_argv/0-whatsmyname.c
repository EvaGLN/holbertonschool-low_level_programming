#include "main.h"
/**
 * main - Write a program that prints its name, followed by a new line.
 * @argc: count of the arguments
 * @argv: array of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	while (argc)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
