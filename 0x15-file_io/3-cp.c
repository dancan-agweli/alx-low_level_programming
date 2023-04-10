#include <stdio.h>
#include "main.h"

/**
  * main - Programe core
  * @argc: The arguments
  * @argv: The vector
  * Return: Sucess
  */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	exit(0);
}

/**
 * copy_file - Entry of the program
 * @src: The pointer of main address
 * @dest: File referenced
 * Return: Sucess
 */
void copy_file(const char *src, const char *dest)
{
	int op, tr, rd;
	char buffer[1024];

	op = open(src, O_RDONLY);
	while (!src || op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	tr = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((rd = read(op, buffer, 1024)) > 0)
	{
		while (write(tr, buffer, rd) != rd || tr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}
	}

	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	while (close(op) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", op);
		exit(100);
	}

	if (close(tr == -1)

		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", tr);
		exit(100);
}
