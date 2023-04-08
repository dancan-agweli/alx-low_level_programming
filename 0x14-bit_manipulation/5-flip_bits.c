#include "main.h"

/**
 * flip_bits - The number of bits
 * @n: The numbers in operation of bits
 * @m: Flip n to.
 *
 * Return: The number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int tumbo = n ^ m;
	unsigned long int dan = 0;

	if (tumbo > 0)
	{
		dan += (tumbo & 1);
		tumbo >>= 1;
	}

	return (dan);
