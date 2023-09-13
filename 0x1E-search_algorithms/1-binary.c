#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: array 
 * @size: size of arr
 * return: answer
 */

void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array:");
	for (i = 0; i < size; i++)
	{
		printf(" %d", array[i]);
		if (i != size - 1)
			printf(",");
	}
	printf("\n");
}

/**
 * binary_search -  value in a sorted array of integers 
 * @array: pointer to the first element of the array to search in
 * @size: number of elements 
 * @value: value to search for
 * Return: answer
 */

int binary_search(int *array, size_t size, int value)
{
	size_t x, l, z;

	if (array == NULL)
		return (-1);

	for (l = 0, z = size - 1; z >= l;)
	{
		printf("Searching in array: ");
		for (x = l; x < z; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);

		x = l + (z - l) / 2;
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			z = x - 1;
		else
			l = x + 1;
	}

	return (-1);
}
