#include "search_algos.h"

/**
 * rec_search -  value in an array using Binary search.
 *
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the number or -1 if not found
 */
int rec_search(int *array, size_t size, int value)
{
	size_t z = size / 2;
	size_t x;

	if (!array || size == 0)
		return (-1);

	printf("Searching in array");

	for (x = 0; x < size; x++)
		printf("%s %d", (x == 0) ? ":" : ",", array[x]);

	printf("\n");

	if (z && size % 2 == 0)
		z--;

	if (value == array[z])
	{
		if (z > 0)
			return (rec_search(array, z + 1, value));
		return ((int)z);
	}

	if (value < array[z])
		return (rec_search(array, z + 1, value));

	z++;
	return (rec_search(array + z, size - z, value) + z);
}

/**
 * advanced_binary - Calls rec_search to return the index
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = rec_search(array, size, value);

	if (i >= 0 && array[i] != value)
		return (-1);

	return (i);
}

