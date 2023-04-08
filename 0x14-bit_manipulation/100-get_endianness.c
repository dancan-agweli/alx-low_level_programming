#include "main.h"
#include <stdlib.h>
/**
 * get_endianness - The endianness.
 *
 * Return: Big return 0 and small return 1 on success
 */
int get_endianness(void)
{
	int dan;
	char *tumbo;

	tumbo = (char *)&dan;
	return (*tumbo + 48);
}
