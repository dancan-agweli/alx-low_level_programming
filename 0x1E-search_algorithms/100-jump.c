#include "search_algos.h"

/**
  * jump_search - Searches for a value in a sorted array using jump search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  * Return: -1 if not found or NULL array, else index where value is found.
  *
  * Description: Prints values compared, jumps, and value found indices.
  */
int jump_search(int *array, size_t size, int value)
{
	size_t x, j, m;

	if (!array || !size)
		return (-1);

	m = sqrt(size);
	for (x = 0, j = 0; j < size && array[j] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		x = j;
		j += m;
	}

	printf("Value found between indices [%ld] and [%ld]\n", x, j);

	j = (j < size - 1) ? j : size - 1;
	for (; x < j && array[x] < value; x++)
		printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	printf("Value checked array[%ld] = [%d]\n", x, array[x]);

	return (array[x] == value ? (int)x : -1);
}

