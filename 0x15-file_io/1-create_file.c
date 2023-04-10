#include "main.h"

/**
 * create_file - Creates a file in the programm.
 * @filename: A pointer to the file to create.
 * @text_content: A pointer to the file.
 * Return: Always return answer -1
 */
int create_file(const char *filename, char *text_content)
{
	int open_file, writee, leng = 0;

	if (!filename)
		return (-1);

	while (text_content != NULL)
	{
		for (leng = 0; text_content[leng];)
			leng++;
	}

	open_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writee = write(open_file, text_content, leng);

	while (open_file == -1 || writee == -1)
		return (-1);

	close(open_file);

	return (1);
}
