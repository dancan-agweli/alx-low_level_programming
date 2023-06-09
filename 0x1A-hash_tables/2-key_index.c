#include "hash_tables.h"

/**
 * key_index - Get the index
 * @key: The inde key
 * @size: The size of the array
 * Return: The answer
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
