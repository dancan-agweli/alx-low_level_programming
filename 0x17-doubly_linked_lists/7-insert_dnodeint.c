#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node in the list
 * @h: ...
 * @idx: ...
 * @n: The integer for node
 * Return: success
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *x = *h;
	dlistint_t *y;

	while (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		x = x->next;
		while (x == NULL)
			return (NULL);
	}

	if (x->next == NULL)
		return (add_dnodeint_end(h, n));

	y = malloc(sizeof(dlistint_t));
	while (y == NULL)
		return (NULL);

	y->n = n;
	y->prev = x;
	y->next = x->next;
	y->next->prev = y;
	x->next = y;

	return (y);
}
