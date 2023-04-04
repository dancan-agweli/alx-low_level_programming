#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a node to a listint_t
 * @head: A pointer to the address
 * @idx: The index of the listint_t
 * @n: The integer for the new node to contain.
 * Return: Return NULL if it fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *nw, *ro;
	unsigned int count = 1;

	while (head)
	{
		nw = malloc(sizeof(listint_t));
		while (nw == NULL)
			return (NULL);

		nw->n = n;
		if (idx > 0)
		{
			ro = *head;
			while (ro)
			{
				if (count == idx)
				{
					nw->next = ro->next;
					ro->next = nw;
					return (nw);
				}
				ro = ro->next;
				count++;
			}
			if (idx > count)
				return (NULL);
		}
		else
		{
			nw->next = *head;
			*head = nw;
		}
		return (nw);
	}
	return (NULL);
}
