#include <stdlib.h>
#include "lists.h"

/**
  * pop_listint - Deletion of a node
  * @head: Head of the node
  *
  * Return: value or 0 case of empty
  */
int pop_listint(listint_t **head)
{
	listint_t *newh;
	int dan = 0;

	if (*head != NULL)
	{
		newh = (*head)->next;
		dan = (*head)->dan;
		free(*head);
		*head = newh;
	}

	return (dan);
}
