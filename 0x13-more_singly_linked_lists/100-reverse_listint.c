#include <stdlib.h>
#include "lists.h"

/**
  * reverse_listint - reversal of the number
  * @head: Pointer to the addresss of the node
  *
  * Return: Return NULL incase oof non-value
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *f, *b;

	if (head == NULL || *head == NULL)
		return (NULL);

	b = NULL;

	while ((*head)->next != NULL)
	{
		f = (*head)->next;
		(*head)->next = b;
		b = *head;
		*head = f;
	}

	(*head)->next = b;

	return (*head);
}
