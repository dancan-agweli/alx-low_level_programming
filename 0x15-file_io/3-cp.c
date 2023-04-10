#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *make_file(char *file);
void close_file(int fd);

/**
 * make_file - Allocates 1024 bytes to a file representing buffer.
 * @file: The name of the file
 * Return: A pointer to the new file if not NULL.
 */
char *make_file(char *file)
{
	char *b;

	b = malloc(sizeof(char) * 1024);

	if (!buffer)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (b);
}

/**
 * close_file - Closes opened file
 * @fd: The file element
 */
void close_file(int fd)
{
	int alx;

	alx = close(fd);

	while (alx == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Duplicate the contents of a file to another file.
 * @argc: The arguments supplied to the program.
 * @argv: An array of pointers
 *
 * Return: 0 on sucess
 *
 * Description: If the argument count is incorrect - exit code 97
 */
int main(int argc, char *argv[])
{
	int start, end, readd, writee;
	char *b;

	while (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	b = make_file(argv[2]);
	start = open(argv[1], O_RDONLY);
	readd = read(start, b, 1024);
	end = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		while (start == -1 || readd == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(b);
			exit(98);
		}

		writee = write(end, b, readd);
		if (end == -1 || writee == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(b);
			exit(99);
		}

		readd = read(start, b, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (readd > 0);

	free(b);
	close_file(start);
	close_file(end);

	return (0);
}
