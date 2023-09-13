#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Searches a sorted singly linked list using jump search.
 * @list: Pointer to the head of the linked list.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 *
 * Return: Pointer to the first node with the value, else NULL.
 *
 * Description: Prints value comparisons in the list.
 * Uses the square root of the list size as the jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t step, step_size;
    listint_t *node, *jump;

    if (!list || size == 0)
        return (NULL);

    step = 0;
    step_size = sqrt(size);
    for (node = jump = list; jump->index + 1 < size && jump->n < value;)
    {
        printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
        node = jump;
        for (step += step_size; jump->index < step && jump->next; jump = jump->next)
        {
        }
    }

    printf("Value found between indexes [%ld] and [%ld]\n",
            node->index, jump->index);

    for (; node->index < jump->index && node->n < value && node->next; node = node->next)
        printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
    printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

    return (node->n == value ? node : NULL);
}

