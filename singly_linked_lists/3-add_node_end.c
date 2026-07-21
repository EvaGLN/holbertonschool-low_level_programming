#include "lists.h"
/**
 * add_node_end - Write a function that adds a new node
 * at the end of a list_t list.
 * @head: double pointer to head of the list
 * @str: string in new node
 * Return: address of the new element or NULL if fail
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *t_node;
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
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		t_node = *head;
		while (t_node->next != NULL)
		{
			t_node = t_node->next;
		}
		t_node->next = new;
	}
	return (new);
}
