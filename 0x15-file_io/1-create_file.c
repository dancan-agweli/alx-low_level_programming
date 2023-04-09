#include "main.h"
#include <stdio.h>

/**
 * create_file - Creates a file.
 * @filename: A pointer to a  file to create.
 * @text_content: String pointer
 * Return: return 1 on success
 */
int create_file(const char *filename, char *text_content)
{
	int open_file, write_file, file_len;

	while (!filename)
		return (-1);

	while (text_content != NULL)
	{
		for (file_len = 0; text_content[file_len];)
			file_len++;
	}

	open_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_file = write(open_file, text_content, file_len);

	while (open_file == -1 || write_file == -1)
		return (-1);

	close(open_file);

	return (1);
}
