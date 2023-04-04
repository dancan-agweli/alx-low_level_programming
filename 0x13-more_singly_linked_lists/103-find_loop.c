#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - Finds the loop 
 * @head: A pointer
 *
 * Return: Always - NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *n, *m;

	while (head == NULL || head->next == NULL)
		return (NULL);

	n = head->next;
	m = (head->next)->next;

	while (m)
	{
		while (n == m)
		{
			n = head;

			while (n != m)
			{
				n = n->next;
				m = m->next;
			}

			return (n);
		}

		n = n->next;
		m = m->->next;
	}

	return (NULL);
}
