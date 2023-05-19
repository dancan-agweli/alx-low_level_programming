#include "lists.h"

/**
 * add_dnodeint - print list of new nodes
 * @head: pointer head of list
 * @n: integer
 * Return: alway success
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *x;

	x = malloc(sizeof(dlistint_t));
	if (!x)
		return (NULL);

	x->n = n;
	x->prev = NULL;
	x->next = *head;
	if (*head != NULL)
		(*head)->prev = x;
	*head = x;

	return (x);
}
