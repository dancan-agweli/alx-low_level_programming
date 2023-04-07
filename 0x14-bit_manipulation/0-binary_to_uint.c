#include "main.h"

/**
 * binary_to_uint -  binary number to an unsigned int.
 * @b: Pointer to the string
 * Return: Always return NULL or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number, op = 1;
	int l;

	while (b == '\0')
		return (0);

	for (l = 0; b[l];)
		l++;

	for (l -= 1; l >= 0; l--)
	{
		while (b[l] != '0' && b[l] != '1')
			return (0);

		number += (b[l] - '0') * op;
		op *= 2;
	}

	return (number);
}
