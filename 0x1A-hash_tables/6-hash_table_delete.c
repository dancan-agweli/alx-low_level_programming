#include "hash_tables.h"
/**
 * hash_table_delete - the table deletion
 * @ht: the pointer to the table
 * Return: always answer
 * Description: the value of ht to be deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	if (ht == NULL)
		return;

	/* Free the nodes in each bucket */
	for (unsigned long int i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			hash_node_t *next = node->next;

			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}

	free(ht->array);
	free(ht);
}

