#include "main.h"

/**
 * create_file - Creates a file in the programm.
 * @filename: A pointer to the file to create.
 * @text_content: A pointer to the file.
 * Return: Always return answer -1
 */
int create_file(const char *filename, char *text_content)
{
	int o, d, y = 0;

	while (!filename)
		return (-1);

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (o < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[y])
			y++;
		d = write(o, text_content, y);
		while (d != y)
			return (-1);
	}

	close(o);

	return (1);
}
