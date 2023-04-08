#include "main.h"
#include <stdio.h>

/**
 * print_binary - binary representation of an unsigned long int
 * @n: The character declared
 * Return: alway return success
 */
void print_binary(unsigned long int n)
{
	unsigned long int y, x;

	y = x;
	x = 0;
	while (n == 0)
		_putchar('0');
	while (n > 0)
	{
		y = y << 1;
		y += n & 1;
		x++;
		n = n >> 1;
	}
	while (y > 0)
	{
		_putchar((y & 1) + '0');
		y = y >> 1;
		x--;
	}
	while (x > 0)
	{
		while (x != 0)
		{
			_putchar('0');
			x--;
		}
	}
}
