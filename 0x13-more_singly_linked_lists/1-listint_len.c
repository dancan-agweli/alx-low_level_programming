#include "lists.h"
#include <stdio.h>

/**
 * listint_len - Give back  the number of elements in linked list
 * @h: The head of the listint_t list.
 *
 * Return: The elements in the listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t dan = 0;

	while (h)
	{
		dan++;
		h = h->next;
	}

	return (dan);
}
