#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer to a hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *data = ht;
	hash_node_t *node, *x;
	unsigned long int x;

	for (x = 0; x < ht->size; x++)
	{
		if (ht->array[x] != NULL)
		{
			node = ht->array[x];
			while (node != NULL)
			{
				x = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = x;
			}
		}
	}
	free(data->array);
	free(data);
}

