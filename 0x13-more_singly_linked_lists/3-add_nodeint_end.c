#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * add_nodeint_end - Adds a new node to the end of a linked list
  * @head: Head of the of singly  linked list
  * @n: The value to add to the end of the linked list
  * Return: Address of the new element, or NULL it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newls, *end;

	if (head)
	{
		newls = malloc(sizeof(listint_t));
		if (newls == NULL)
			return (NULL);

		newls->n = n;
		newls->next = NULL;

		if (*head == NULL)
		{
			*head = newls;
			return (*head);
		}
		else
		{
			end = *head;
			while (end->next)
				end = end->next;

			end->next = newls;
			return (end);
		}
	}

	return (NULL);
}
