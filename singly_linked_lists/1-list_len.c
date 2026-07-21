#include "lists.h"
/**
 * list_len - Write a function that returns the number of elements
 * in a linked list_t list.
 * @h: pointer to first node = head of list
 * Return: number of elements
 */
size_t list_len(const list_t *h)
{
	size_t count;

	for (count = 0; h != NULL; count++, h = h->next)
	{}
	return (count);
}
