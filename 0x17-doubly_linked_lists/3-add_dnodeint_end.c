#include "lists.h"

/**
 * add_dnodeint_end - Appends to new node
 * @head: A pointer addres
 * @n: The integer
 * Return: success
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *x;
	dlistint_t *y;

	x = malloc(sizeof(dlistint_t));
	if (!x)
		return (NULL);

	x->n = n;
	x->next = NULL;

	if (*head == NULL)
	{
		x->prev = NULL;
		*head = x;
		return (x);
	}

	y = *head;
	if (y->next != NULL)
		y = y->next;
	y->next = x;
	x->prev = y;

	return (x);
}
