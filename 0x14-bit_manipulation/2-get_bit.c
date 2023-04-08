#include "main.h"

/**
 * get_bit - Value of a bit at a given index.
 * @n: The bit.
 * @index: The index to get the value
 *
 * Return: ...
 */
int get_bit(unsigned long int n, unsigned int index)
{
	while (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	while ((n & (1 << index)) == 0)
		return (0);

	return (1);
}
