#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 *
 * @ht: A pointer to a hash table.
 * Return: answer always
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *data = ht;
	hash_node_t *node, *x;
	unsigned long int w;

	for (w = 0; w < ht->size; w++)
	{
		if (ht->array[w] != NULL)
		{
			node = ht->array[w];
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
