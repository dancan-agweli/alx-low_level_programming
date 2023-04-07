#include "main.h"
#include <unistd.h>

/**
 * _putchar - Prints character c in  stdout
 * @c: The character
 * Return: Always return success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
