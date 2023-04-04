#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * delete_nodeint_at_index - Delete the node
  * @head: The pointer to the address
  * @index: The node to be deleted
  *
  * Return: 1
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 1;
	listint_t *new_node = *head, *p;

	while (!head || !*head)
		return (-1);

	while (index == 0)
	{
		*head = new_node->next;
		free(new_node);
		return (1);
	}

	p = *head;
	while (p)
	{
		if (count == index)
		{
			new_node = p->next;
			p->next = new_node->next;
			free(new_node);
			return (1);
		}

		p = p->next;
		count++;
	}

	return (-1);
}
