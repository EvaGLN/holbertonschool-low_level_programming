#include "lists.h"
/**
 * insert_dnodeint_at_index - Write a function
 * that inserts a new node at a given position.
 * @h: double pointer to head of the list
 * @idx: index of the new node
 * @n: integer in new node
 * Return: the address of the new node or NULL if fail
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp, *prev_node;
	size_t len, i;

	for (len = 0, temp = *h; temp != NULL; len++, temp = temp->next)
		;
	if (idx > len)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (idx == len)
		return (add_dnodeint_end(h, n));
	prev_node = *h;
	for (i = 0; i < idx - 1; i++, prev_node = prev_node->next)
		;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = prev_node;
	new->next = prev_node->next;
	prev_node->next->prev = new;
	prev_node->next = new;
	return (new);
}
