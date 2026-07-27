#include "lists.h"
/**
 * add_dnodeint_end - Write a function that adds a new node
 * at the end of a dlistint_t list.
 * @head: double pointer to head of the list
 * @n: integer in new node
 * Return: the address of the new element or NULL if fail
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *t_node;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		t_node = *head;
		while (t_node->next != NULL)
			t_node = t_node->next;
		t_node->next = new;
		new->prev = t_node;
	}
	return (new);
}
