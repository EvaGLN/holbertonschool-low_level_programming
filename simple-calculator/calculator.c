#include <stdio.h>
/**
 * main: 
 * Return: always 0
 */
int main ()
{
	int choice = -1;
	int A = 0;
	int B = 0;
	int result = 0;

	printf("Welcome to the Simple Calculator!\n");

	while (choice)
	{
		printf("Simple Calculator\n1) Add\n2) Subtract\n");
		printf("3) Multiply\n4) Divide\n0) Quit\n");
		printf("Choice: \n");
		scanf("%d", &choice);

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if	(choice == 1)
		{
			printf("What's you first number to add?\n");
			scanf("%d", &A);
			printf("What's your second number to add?\n");
			scanf("%d", &B);
			result = A + B;
			printf("Result: %d\n", result);
		}
		else if (choice == 2)
		{
			printf("What's you first number to subtract?\n");
			scanf("%d", &A);
			printf("What's your second number to subtract?\n");
			scanf("%d", &B);
			result = A - B;
			printf("Result: %d\n", result);
		}
		else if (choice == 3)
		{
			printf("What's you first number to multiply?\n");
			scanf("%d", &A);
			printf("What's your second number to multiply?\n");
			scanf("%d", &B);
			result = A * B;
			printf("Result: %d\n", result);
		}
		else if (choice == 4)
		{
			printf("What's you first number to divide?\n");
			scanf("%d", &A);
			printf("What's your second number to divide?\n");
			scanf("%d", &B);
			result = A / B;
			printf("Result: %d\n", result);
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	return (0)
}
