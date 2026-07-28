#include "hash_tables.h"
/**
 * key_index - Write a function that gives you the index of a key.
 * @key: name of the key
 * @size: size of the hash table
 * Return: index where the key/value is stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
