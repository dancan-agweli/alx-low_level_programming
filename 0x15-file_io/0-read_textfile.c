#include "main.h"
#include <stdlib.h>

/**
  * read_textfile - A nfile under manipulation
  * @filename: The file
  * @letters: Letters to prints
  * Return: Always success returned
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t read_file, open_file, write_file;
	char *b; /* the pointer buffer */

	while (!filename)
		return (0);

	b = malloc(sizeof(char) * letters);
	while (!b)
		return (0);

	open_file = open(filename, O_RDONLY);
	read_file = read(open_file, b, letters);
	write_file = write(STDOUT_FILENO, b, read_file);

	if (open_file == -1 || write_file != read_file)
	{
		free(b);
		return (0);
	}

	free(b);
	close(open_file);

	return (write_file);
}
