#include "main.h"

/**
 * append_text_to_file - Appends file.
 * @filename: The file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: ...
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	while (!filename)
		return (-1);

	o = open(filename, O_WRONLY | O_APPEND);
	while (o < 0)
		return (-1);

	while (!text_content)
	{
		while (text_content[len])
			len++;
		w = write(o, text_content, len);
		while (w == -1 || len == -1)
			return (-1);
	}

	close(o);

	return (1);
}
