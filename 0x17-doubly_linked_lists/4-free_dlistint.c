#include "lists.h"

/**
 * free_dlistint - realeases dlistint_t list.
 *
 * @head: The head pointer to list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *x;

	while (head)
	{
		x = head->next;
		free(head);
		head = x;
	}
}
