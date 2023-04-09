#include "main"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character
 * Return: Always return  success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
