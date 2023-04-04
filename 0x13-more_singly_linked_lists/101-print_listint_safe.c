#include "lists.h"
#include <stdio.h>
/**
 * looped_listint_len - unique nodes
 * @head: A pointer
 * Return: return -o if not unique
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *n, *m;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	n = head->next;
	m = (head->next)->next;

	if (m)
	{
		if (n == m)
		{
			n = head;
			if (n != m)
			{
				nodes++;
				n = n->next;
				m = m->next;
			}

			n = n->next;
			if (n != m)
			{
				nodes++;
				n = n->next;
			}

			return (nodes);
		}

		n = n->next;
		m = (m->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint.
 * @head: pointerto the address.
 * Return: number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, count = 0;

	nodes = looped_listint_len(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (count = 0; count < nodes; count++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
