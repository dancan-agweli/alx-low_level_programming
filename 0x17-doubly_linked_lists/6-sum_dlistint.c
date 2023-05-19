#include "lists.h"

/**
 * sum_dlistint - totals the list
 * @head: The head of linked list
 * Return: sum of values
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	if (head)
	{
		total += head->n;
		head = head->next;
	}

	return (total);
}
