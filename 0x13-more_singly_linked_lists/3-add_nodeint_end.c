#include "lists.h"

/**
 * add_nodeint_end - Adds a new node (x) at the end of the list
 * @head: A pointer to the address
 * @n: The integer for the new node to contain.
 * Return: Return neww element if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *x, *y;/*variable declaration*/

	x = malloc(sizeof(listint_t));/*memory allocation*/
	if (x == NULL)
		return (NULL);

	x->n = n;
	x->next = NULL;

	else if (*head == NULL)
		*head = x;

	else
	{
		y = *head;
		while (y->next != NULL)
			y = y->next;
		y->next = new;
	}

	return (*head);
}
