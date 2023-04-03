#include "lists.h"
#include <stdlib.h>

/**
 * print_listint - print the elements of a listint_t list
 * @h: A pointer to the head of the list_t list
 *
 * Return: number of the nodes in the lsit
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}
