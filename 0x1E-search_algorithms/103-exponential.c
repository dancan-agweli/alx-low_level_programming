#include "search_algos.h"

/**
 * _binary_search - Binary search in a sorted array.
 * @array: Pointer to the first element of the array.
 * @left: Left index of the search range.
 * @right: Right index of the search range.
 * @value: Value to search for.
 * Return: Index of the value if found, -1 otherwise.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
    size_t w;

    if (!array)
        return (-1);

    while (right >= left)
    {
        printf("Searching in array: ");
        for (w = left; w < right; w++)
            printf("%d, ", array[w]);
        printf("%d\n", array[w]);

        w = left + (right - left) / 2;
        if (array[w] == value)
            return (w);
        if (array[w] > value)
            right = w - 1;
        else
            left = w + 1;
    }

    return (-1);
}

/**
 * exponential_search - Exponential search in a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: Index of the value if found, -1 otherwise.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t w = 0, right;

    if (!array)
        return (-1);

    if (array[0] != value)
    {
        for (w = 1; w < size && array[w] <= value; w = w * 2)
            printf("Value checked array[%ld] = [%d]\n", w, array[w]);
    }

    right = w < size ? w : size - 1;
    printf("Value found between indexes [%ld] and [%ld]\n", w / 2, right);
    return (_binary_search(array, w / 2, right, value));
}

