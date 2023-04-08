#include "main.h"

/**
 * print_binary - Binary representation of a number.
 *
 * @n: The number of binary
 * Return: Always success
 */
void print_binary(unsigned long int n)
{
	while (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
