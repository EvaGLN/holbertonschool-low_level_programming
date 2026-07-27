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
