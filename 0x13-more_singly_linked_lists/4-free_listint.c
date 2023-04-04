#include <stdlib.h>
#include "lists.h"

/**
  * free_listint - Free singly linked list
  * @head: The head of the singly linked list
  *
  * Return: 0
  */
void free_listint(listint_t *head)
{
	listint_t *freez;

	while (head)
	{
		freez = head;
		head = head->next;
		free(freez);
	}

	free(head);
}
