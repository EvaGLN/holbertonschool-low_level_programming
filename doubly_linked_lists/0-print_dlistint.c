#include "main.h"
/**
 * print_dlistint - Write a function that prints all the elements of a dlistint_t list.
 * @h: pointer to the first node = head of list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count;

	for (count = 0; h!= NULL, count ++, h = h-<next)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
	}
	return (count);
}
