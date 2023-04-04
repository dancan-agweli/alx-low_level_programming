#include "lists.h"

/**
 * add_nodeint - Addition of a new node at the start of singly linked list
 * @head: A pointer to the address of a node
 * @n: The integer for the new node to contain.
 * Return: If the function fails - NULL or new
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *x;

	x = malloc(sizeof(listint_t));/* memory allocation*/
	if (x == NULL)
		return (NULL);

	x->n = n;
	x->next = *head;

	*head = x;

	return (x);
}
