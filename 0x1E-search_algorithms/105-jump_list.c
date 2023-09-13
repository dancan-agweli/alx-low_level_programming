#include "search_algos.h"

/**
 * jump_list - Search in sorted singly linked list using jump search.
 * @list: linked list to search.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 * Return: Pointer to first node
 * Description: Prints value compared in the list.
 * Uses sqrt of list size as the jump step (xx).
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t xx, xx_size;
	listint_t *node, *m;

	if (!list || size == 0)
		return (NULL);

	xx = 0;
	xx_size = sqrt(size);
	for (node = m = list; m->index + 1 < size && m->n < value;)
	{
		node = m;
		for (xx += xx_size; m->index < xx; m = m->next)
		{
			if (m->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", m->index, m->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, m->index);

	for (; node->index < m->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}

