#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Search for value in array using Jump search.
 * @array: Input array.
 * @size: Array size.
 * @value: Value to find.
 * Return: Index of value, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	int y, m, nextt, prev;

	if (!array || size == 0)
		return (-1);

	m = (int)sqrt((double)size);
	nextt = 0;
	prev = y = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", y, array[y]);

		if (array[y] == value)
			return (y);
		prev = y;
		y++;
		nextt = y * m;
	} while (nextt < (int)size && array[nextt] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, nextt);

	for (; prev <= nextt && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}

