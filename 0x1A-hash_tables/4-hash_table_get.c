#include "hash_tables.h"

/**
 * hash_table_get - print the value to hash table
 * @ht: A pointer to the hash table.
 * @key: The key value
 * Return: answer always
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *w;
	unsigned long int x;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	x = key_index((const unsigned char *)key, ht->size);
	if (x >= ht->size)
		return (NULL);

	w = ht->array[x];
	while (w && strcmp(w->key, key) != 0)
		w = w->next;

	return ((w == NULL) ? NULL : w->value);
}

