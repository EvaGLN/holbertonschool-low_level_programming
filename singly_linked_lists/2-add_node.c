#include "lists.h"
/**
 * add_node - Write a function that adds a new node
 * at the beginning of a list_t list.
 * @head: double pointer to head of the list
 * @str: string in new node
 * Return: address of the new element or NULL if fail
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	int i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{}
	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->len = i;
	new->next = *head;
	*head = new;
	return (new);
}
