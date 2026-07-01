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

	printf("Welcome to the Simple Calculator!");

	while (choice != 0)
	{
		printf("Simple Calculator\n1) Add\n2) Substract\n");
		printf("3) Multiply\n4) Divide\n0) Quit\n");
		scanf("%d\n", &choice);

		if (choice == 0)
		{
			printf("Bye!\n");
		}
		else if	(choice == 1)
		{
			printf("What's you first number to add?\n");
			scanf("%d\n", &A);
			printf("What's your second number to add?\n");
			scanf("%d\n", &B);
			result = A + B;
			printf("Result: %d\n", result);
		}
		else if (choice == 2)
		{
			printf("What's you first number to substract?\n");
			scanf("%d\n", &A);
			printf("What's your second number to substract?\n");
			scanf("%d\n", &B);
			result = A - B;
			printf("Result: %d\n", result);
		}
		else if (choice == 3)
		{
			printf("What's you first number to multiply?\n");
			scanf("%d\n", &A);
			printf("What's your second number to multiply?\n");
			B = int scanf("%d\n", &B);
			result = A * B;
			printf("Result: %d\n", result);
		}
		else if (choice == 4)
		{
			printf("What's you first number to divide?\n");
			scanf("%d\n", &A);
			printf("What's your second number to divide?\n");
			scanf("%d\n", &B);
			result = A / B;
			printf("Result: %d\n", result);
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
}
