#include "lists.h"

/**
 * get_dnodeint_at_index - node in a dlistint_t list.
 * @head: The pointer to list
 * @index: The node of the list
 * Return: alwys answer
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (!head)
			return (NULL);
		head = head->next;
	}

	return (head);
}
