#include "main.h"

/**
 * clear_bit - Value of a bit
 * @n: A pointer to th value of abit  bit.
 * @index: Index
 * Return: ..
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	while (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
