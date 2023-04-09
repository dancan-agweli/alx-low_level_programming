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
	int o, w, l = 0;

	while (!filename)
		return (-1);

	while (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, l);

	while (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
