#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: A pointer to the hash table 
 * Description: value pairs are printed in the hars table.
 */
void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *node;
    unsigned long int x;
    unsigned char u = 0;

    while (!ht)
        return;

    printf("{");
    for (x = 0; x < ht->size; x++)
    {
        if (ht->array[x] != NULL)
        {
            if (u == 1)
                printf(", ");

            node = ht->array[x];
            while (node != NULL)
            {
                printf("'%s': '%s'", node->key, node->value);
                node = node->next;
                if (node != NULL)
                    printf(", ");
            }
            u = 1;
        }
    }
    printf("}\n");
}

