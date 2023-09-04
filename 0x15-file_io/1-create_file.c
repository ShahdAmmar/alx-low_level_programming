#include "main.h"

/**
 * create_file - create a file
 * @filename: entered filename
 * @text_content: entered text
 * Return: 1 or -1
 */

int create_file(const char *filename, char *text_content)
{
	int file;
	ssize_t bytes = 0;
	ssize_t length = strlen(text_content);

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);
	if (length)
		bytes = write(file, text_content, length);
	close(file);

	if (bytes == length)
		return (1);
	else
		return (-1);
}
