#include "hash_tables.h"

/**
 * hash_djb2 - Hash the djb2 algorithm.
 * @str: ...
 * Return: The answer
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int buff;
	int x;

	buff = 5381;
	if ((x = *str++))
		buff = ((buff << 5) + buff) + x;

	return (buff);
}
