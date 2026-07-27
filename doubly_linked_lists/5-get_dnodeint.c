#include "lists.h"
/**
 * get_dnodeint_at_index - Write a function that returns
 * the nth node of a dlistint_t linked list.
 * @head: pointer to first node = head of list
 * @index: index of the node
 * Return: the nth node of a DLL or NULL if node doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head != NULL; i++, head = head->next)
		if (i == index)
			return (head);
	return (NULL);
}
