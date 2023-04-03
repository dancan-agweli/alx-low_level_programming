#include "lists.h"
#include <stdio.h>

/**
 * print_listint - print the elements of a listint_t list
 * @h: head of the list_t list
 *
 * Return: number of the nodes in the lsit
 */
size_t print_listint(const listint_t *h)
{
	int nodes = 0;

	if(h != NULL)
	{
		while (h)
		nodes++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodes);
}
