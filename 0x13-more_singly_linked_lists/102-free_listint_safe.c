#include "lists.h"
#include <stdlib.h>

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - unique node
 * @head: pointer to the head of the listint_t.
 *
 * Return: return unique nodes.
 */
size_t looped_listint_count(listint_t *head)
{
	listint_t *dan, *tumbo;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	dan = head->next;
	tumbo = (head->next)->next;

	if (tumbo)
	{
		if (dan == tumbo)
		{
			dan = head;
			while (dan != tumbo)
			{
				nodes++;
				dan = dan->next;
				tumbo = tumbo->next;
			}

			dan = dan->next;
			while (dan != tumbo)
			{
				nodes++;
				dan = dan->next;
			}

			return (nodes);
		}

		dan = dan->next;
		tumbo = (tumbo->next)->next;
	}

	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list
 * @h: pointer to the address
 * Return: The size of the list.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *p;
	size_t nodes, countt;

	nodes = looped_listint_count(*h);

	if (nodes == 0)
	{
		for (; h != NULL && *h != NULL; nodes++)
		{
			p = (*h)->next;
			free(*h);
			*h = p;
		}
	}

	else
	{
		for (countt = 0; countt < nodes; countt++)
		{
			p = (*h)->next;
			free(*h);
			*h = p;
		}

		*h = NULL;
	}

	h = NULL;

	return (nodes);
}
