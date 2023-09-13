#include "search_algos.h"

/**
 * linear_search - searches for a value in an arra
 * @array: input dat of array
 * @size: size of array
 * @value: value to searchin array
 * Return: sucees
 */
int linear_search(int *array, size_t size, int value)
{
	int x;

	if (!array)
		return (-1);

	for (x = 0; x < (int)size; x++)
	{
		printf("Value checked array[%u] = [%d]\n", x, array[x]);
		if (value == array[x])
			return (x);
	}
	return (-1);
}
