#include <stdlib.h>
#include "lists.h"
#include <stdio.h>

/**
  * get_nodeint_at_index - Printh nth of the code
  * @head: Pointer address
  * @index: element
  *
  * Return: nth
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int ind = 0;

	if (head)
	{
		while (head)
		{
			if (ind == index)
				return (head);

			head = head->next;
			ind++;
		}
	}

	return (NULL);
}
