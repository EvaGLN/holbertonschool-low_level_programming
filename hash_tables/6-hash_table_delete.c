#include "hash_tables.h"
/**
 * hash_table_delete - Write a function that deletes a hash table.
 * @ht: pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *temp; *next_node;

	if (ht == NULL)
		return;
	for (index = 0; index < ht->size; index++)
	{
		temp = ht->array[index];
		while (temp)
		{
			next_node = temp->next;
			free(temp->key);
			free(temp->value);
			free(temp);
			temp = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
