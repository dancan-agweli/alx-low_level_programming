#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in an array
 * @array: Input array
 * @size: Size of the array
 * @value: Value to search
 * Return: answwer
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t v, l, h;
	double w;

	if (array == NULL)
		return (-1);

	l = 0;
	h = size - 1;

	while (size)
	{
		w = (double)(h - l) / (array[h] - array[l]) * (value - array[l]);
		v = (size_t)(l + w);
		printf("Value checked array[%d]", (int)v);

		if (v >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
		{
			printf(" = [%d]\n", array[v]);
		}

		if (array[v] == value)
			return ((int)v);

		if (array[v] < value)
			l = v + 1;
		else
			h = v - 1;

		if (l == h)
			break;
	}

	return (-1);
}
