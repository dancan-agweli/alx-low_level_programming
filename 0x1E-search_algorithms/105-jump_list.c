#include "search_algos.h"

/**
 * jump_list - Searches in a sorted singly linked list using jump search.
 * @list: Pointer to the head of the linked list to search.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to first node where value is found, or NULL.
 *
 * Description: Prints values compared, using sqrt of list size as jump.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t s, step_size;
	listint_t *buf, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	s = 0;
	step_size = sqrt(size);
	for (buf = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		buf = jump;
		for (s += step_size; jump->index < s; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			buf->index, jump->index);

	for (; buf->index < jump->index && buf->n < value; buf = buf->next)
		printf("Value checked at index [%ld] = [%d]\n", buf->index, buf->n);
	printf("Value checked at index [%ld] = [%d]\n", buf->index, buf->n);

	return (buf->n == value ? buf : NULL);
}

