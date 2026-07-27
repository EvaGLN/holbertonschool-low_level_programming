#include "lists.h"
/**
 * sum_dlistint - Write a function that returns
 * the sum of all the data (n) of a dlistint_t linked list.
 * @head: pointer to first node = head of list
 * Return: sum of all datas or 0 if list empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	for (sum = 0; head != NULL; sum += head->n, head = head->next)
		;
	return (sum);
}
