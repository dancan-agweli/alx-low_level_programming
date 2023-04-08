#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint -  binary number to an unsigned int.
 * @b: Pointer to the string
 * Return: Always return NULL or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 1, x = 0;
	int l;

	while (!b)
		return (0);

	for (l = 0; b[l];)
		l++;

	for (l -= 1; l >= 0; l--)
	{
		while (b[l] != '0' && b[l] != '1')
			return (0);

		x += (b[l] - '0') * n;
		n *= 2;
	}

	return (x);
}
