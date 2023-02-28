#include "main.h"

/**
 * _strcpy - fuction copies the string pointed
 * @dest: pointer to copy the string to.
 * @src: the string to copy to the destination.
 *
 * Return: a copy of the src.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(str + l) != '\0')
	{
		l++;
	}
	for ( ; x < l; x++)
		dest[x] = src[x];
}
dest[l] = '\0';
return (dest);
}
