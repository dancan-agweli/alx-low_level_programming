#include <stdlib.h>
#include "lists.h"

/**
  * free_listint2 - Free singly linked list
  * @head: head to the node
  *
  * Return: 0 case of NULL
  */
void free_listint2(listint_t **head)
{
	listint_t *p;

	if (head)
	{
		while (*head)
		{
			p = (*head);
			*head = (*head)->next;
			free(p);
		}
	}
	else
	{
		return;
	}

	free(*head);
	head = 0;
}
