#include "main.h"
#include <unistd.h>

/**
 * _putchar - protyotype of putchar
 * Return: always (sucess) 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
