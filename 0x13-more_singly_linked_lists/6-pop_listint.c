#include <stdlib.h>
#include "lists.h"

/**
  * pop_listint - Deletion of a node
  * @head: Pointer address to Head of the node
  *
  * Return: Value or 0 case of empyu
  */
int pop_listint(listint_t **head)
{
	listint_t *p;
	int y;

	if (*head == NULL)
		return (0);

	p = *head;
	y = (*head)->n;
	*head = (*head)->next;

	free(p);

	return (y);
}

