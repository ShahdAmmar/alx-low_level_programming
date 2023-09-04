#include "main.h"

/**
 * _strlen - length of string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
        int slen = 0;

        while (*s != '\0')
        {
                slen++;
                s++;
        }
        return (slen);
}

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
	ssize_t length = _strlen(text_content);

	if (!filename)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (length)
		bytes = write(file, text_content, length);
	if (file == -1 || bytes == -1)
		return (-1);
	close(file);

	if (bytes == length)
		return (1);
	else
		return (-1);
}
