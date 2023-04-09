#include "holberton.h"

/**
  * read_textfile - A nfile under manipulation
  * @filename: The file
  * @letters: Letters to prints
  * Return: Always success returned
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int x, y; /* b is the pointer buffer , be is the variable to be read*/
	char *b = malloc(sizeof(char *) * letters);

	while (!b)
		return (0);

	while (!filename) /* while output is not the file return 0*/
		return (0);

	x = open(filename, O_RDONLY, 0600);
	while (x == -1)
		return (0);

	y = read(x, b, letters);
	write(STDOUT_FILENO, b, y);

	free(b);
	close(x);
	return (y);
}
