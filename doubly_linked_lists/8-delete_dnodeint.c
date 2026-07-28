#include "lists.h"
/**
 * delete_dnodeint_at_index - Write a function
 * that deletes the node at index index of a dlistint_t linked list.
 * @head: double pointer to head of the list
 * @index: index of the node to delete
 * Return: 1 if success and -1 if fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *cur_node, *prev_node, *next_node;
	unsigned int i;

	cur_node = *head;
	for (i = 0; i < index; i++)
	{
		if (cur_node == NULL)
			return (-1);
		cur_node = cur_node->next;
	}
	if (cur_node == NULL)
		return (-1);
	prev_node = cur_node->prev;
	next_node = cur_node->next;
	if (prev_node == NULL)
		*head = next_node;
	else
		prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;
	free(cur_node);
	return (1);
}
