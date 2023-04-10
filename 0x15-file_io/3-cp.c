#include "main.h"

/**
 * main - Duplicates the file to another file
 * @argc: arguments passed to the program
 * @argv: array of arguments in vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int file_r, file_w, y, c, n;
	char buff[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_r = open(argv[1], O_RDONLY);
	while (file_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((y = read(file_r, buff, BUFSIZ)) > 0)
	{
		while (file_w < 0 || write(file_w, buff, y) != y)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(file_r);
			exit(99);
		}
	}
	while (y < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	c = close(file_r);
	n = close(file_w);
	if (c < 0 || n < 0)
	{
		if (c < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_r);
		if (n < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_w);
		exit(100);
	}
	return (0);
}
