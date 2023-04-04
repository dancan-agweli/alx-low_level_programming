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
	listint_t *bef = NULL, *next = NULL;

while (head)
	{
		while (*head)
		{
			next = *head;
			*head = (*head)->next;
			next->next = bef;
			bef = next;
		}

		*head = bef;
		return (*head);
	}

	return (NULL);
}
