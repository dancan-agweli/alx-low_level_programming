#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node from list
 * @head: A pointer to address
 * @index: ...
 * Return: succcess always
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *x = *head;

	if (*head == NULL)
		return (-1);

	for (; index != 0; index--)
	{
		if (!x)
			return (-1);
		x = x->next;
	}

	if (x == *head)
	{
		*head = x->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}

	else
	{
		x->prev->next = x->next;
		if (x->next != NULL)
			x->next->prev = x->prev;
	}

	free(x);
	return (1);
}
