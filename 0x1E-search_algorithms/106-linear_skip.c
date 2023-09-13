#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a skip list
 * @list: Input list.
 * @value: Value to search for.
 * Return: Pointer to the node with the value, or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *dan;

	if (list == NULL)
		return (NULL);
	dan = list;
	while (dan)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)dan->index, dan->n);

		if (!dan->express || dan->express->n >= value)
		{
			if (dan->n == value)
				return (dan);

			dan = dan->next;
		}
		else
		{
			dan = dan->express;
		}
	}

	return (NULL);
}

