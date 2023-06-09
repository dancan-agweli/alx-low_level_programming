#include "hash_tables.h"

/**
 * hash_table_set - element in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key
 * @value: The value
 * Return: answer
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *w;
	char *vc;
	unsigned long int x, i;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	vc = strdup(value);
	if (vc == NULL)
		return (0);

	x = key_index((const unsigned char *)key, ht->size);
	for (i = x; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = vc;
			return (1);
		}
	}

	w = malloc(sizeof(hash_node_t));
	if (w == NULL)
	{
		free(vc);
		return (0);
	}
	w->key = strdup(key);
	if (w->key == NULL)
	{
		free(w);
		return (0);
	}
	w->value = vc;
	w->next = ht->array[x];
	ht->array[x] = w;

	return (1);
}
