#include "lists.h"
/**
 * add_dnodeint - Write a function that adds a new node
 * at the beginning of a dlistint_t list.
 * @head: double pointer to head of the list
 * @n: integer in new node
 * Return: the address of the new element or NULL if fail
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)-> =new;
	*head = new;
	return(new);
}
