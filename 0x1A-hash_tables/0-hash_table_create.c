#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the size or arry
 * Return: always success
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *buff;
	unsigned long int c;

	buff = malloc(sizeof(hash_table_t));
	if (buff == NULL)
		return (NULL);
	buff->size = size;
	buff->array = malloc(size * sizeof(hash_table_t *));
	if (buff->array == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (c = 0; c < size; c++)
		buff->array[c] = NULL;
	return (buff);
}
