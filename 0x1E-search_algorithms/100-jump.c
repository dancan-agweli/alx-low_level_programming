#include "search_algos.h"

/**
 * jump_search - Search in sorted array using jump search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: Index of the value, or -1 if not found.
 *
 * Description: Prints value comparisons in the array.
 * Uses the square root of the array size as the jump step.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t w, j, step;

	if (!array || size == 0)
		return (-1);

	step = sqrt(size);
	for (w = j = 0; j < size && array[j] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		w = j;
		j += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", w, j);

	j = j < size - 1 ? j : size - 1;
	for (; w < j && array[w] < value; w++)
		printf("Value checked array[%ld] = [%d]\n", w, array[w]);
	printf("Value checked array[%ld] = [%d]\n", w, array[w]);

	return (array[w] == value ? (int)w : -1);
}

