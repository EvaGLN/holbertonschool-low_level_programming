#include "lists.h"
/**
 * dlistint_len - Write a function that returns
 * the number of elements in a linked dlistint_t list.
 * @h: pointer to first node = head of list
 * Return: the number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count;

	for (count = 0; h != NULL; count++, h = h->next)
		;
	return (count);
}
