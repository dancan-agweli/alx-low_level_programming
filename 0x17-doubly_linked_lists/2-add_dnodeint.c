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
	dlistint_t *no = malloc(sizeof(dlistint_t));


	if (!no)
		return (NULL);
	no->n = n;
	no->prev = NULL;
	no->next = NULL;

	while (*head == NULL)
	{
		no->next = NULL;
		*head = no;
		return (*head);
	}
	x = *head;
	no->next = x;
	x->prev = no;
	*head = no;
	return (no);
}
