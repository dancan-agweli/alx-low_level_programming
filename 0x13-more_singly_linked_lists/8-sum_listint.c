#include "lists.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * sum_listint - Calculates the sum
 * @head: A pointer to the head of the listint_t list.
 * Return: Return sum or 0 when empty
 */
int sum_listint(listint_t *head)
{
        int addition;

        if (head)
        {
                addition += head->n;
                head = head->next;
        }

        return (addition);
}
