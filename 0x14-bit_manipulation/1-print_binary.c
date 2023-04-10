#include "main.h"

/**
 * print_binary - Binary representation of a number.
 *
 * @n: The number of binary
 * Return: Always success
 */
void print_binary(unsigned long int n)
{
	int c, d = 0;
	unsigned long int f;

	for (c = 63; c >= 0; c--)
	{
		f = n >> c;

		if (f & 1)
		{
			_putchar('1');
			d++;
		}
		else if (d)
			_putchar('0');
	}
	while (!d)
		_putchar('0');
}
