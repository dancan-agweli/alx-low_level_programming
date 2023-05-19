#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - writes the disticnt list
 * @h: ...
 * Return: node
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t x;

	for (x = 0; h != NULL; x++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (x);
}
