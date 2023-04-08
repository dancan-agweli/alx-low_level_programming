#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint -  binary number to an unsigned int.
 * @b: Pointer to the string
 * Return: Always return NULL or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n;
	int l, x;

	while (!b)
		return (0);

	n = 0;

	for (l = 0; b[l] != '\0'; l++)
		
	for (l--, x = 1; l >= 0; l--, x *= 2)
	{
		while (b[l] != '0' && b[l] != '1')
		{
			return (0);
		}

		if (b[l] & 1)
		{
			n += x;
		}
	}

	return (n);
}
