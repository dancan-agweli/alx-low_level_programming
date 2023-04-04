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
	listint_t *nw, *duplicate = *head;
	unsigned int no;

	nw = malloc(sizeof(listint_t));
	if (nw == NULL)
		return (NULL);

	nw->n = n;

	if (idx == 0)
	{
		nw->next = copy;
		*head = nw;
		return (nw);
	}

	for (no = 0; no < (idx - 1); no++)
	{
		if (duplicate == NULL || duplicate->next == NULL)
			return (NULL);

		duplicate = duplicate->next;
	}

	nw->next = duplicate->next;
	duplicate->next = nw;

	return (nw);
}
