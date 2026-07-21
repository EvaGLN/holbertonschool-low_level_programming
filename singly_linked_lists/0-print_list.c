#include "lists.h"
/**
 * print_list - Write a function that prints all the elements of a list_t list.
 * @h: pointer to first node = head of list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count;

	for (count = 0; h != NULL; count++, h = h->next)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
	}
	return (count);
}
