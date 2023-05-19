#include "lists.h"

/**
 * sum_dlistint - totals the list
 * @head: The head of linked list
 * Return: sum of values
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *x = head;
	int sum = 0;

	if (head)
	{
		while (x != NULL)
		{
			sum += x->n;
			x = x->next;
		}
	}

	return (sum);
}
