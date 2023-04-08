#include "main.h"

/**
 * set_bit - Assign the value of a bitto 1.
 * @n: Pointer to the bit.
 * @index: The index
 *
 * Return: Always success
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	while (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);

	return (1);
}
