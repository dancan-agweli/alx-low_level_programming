#include "search_algos.h"

/**
 * recursive_search - Searches for a value in an array using Binary search.
 *
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the number or -1 if not found
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t n;
	size_t pp;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (n = 0; n < size; n++)
		printf("%s %d", (n == 0) ? ":" : ",", array[n]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_search(array, half, value));

	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 * binary_search - Calls recursive_search to return the index of the number.
 *
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the number or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
/**
 * exponential_search - Searches for a value in an array
 *
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search for
 * Return: Index of the number or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t n;
	size_t pp;
	int result;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	n = 1;

	while (array[n] < value && n < size)
	{
		printf("Value checked array[%d] = [%d]\n", (int)n, array[n]);
		n *= 2;
	}

	pp = (n >= size) ? (size - 1) : n;

	n /= 2;

	printf("Value found between indexes [%d] and [%d]\n", (int)n, (int)pp);

	result = binary_search(array + n, (pp + 1) - n, value);

	if (result >= 0)
		result += n;

	return (result);
}

