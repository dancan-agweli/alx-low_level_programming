#include "lists.h"

/**
 * dlistint_len - print the doublelist
 * @h: pointer address
 * Return: nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t x;

	for (x = 0; h != NULL; x++)
		h = h->next;
	return (x);
}
