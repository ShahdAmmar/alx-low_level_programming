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
 * append_text_to_file - add text at the end of a file
 * @filename: name of text file
 * @text_content: text to add  to the file
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, w_data, slen = 0;

	if (!filename)
		return (-1);
	if (text_content != NULL)
		slen = _strlen(text_content);

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);
	w_data = write(file, text_content, slen);
	if (w_data == -1)
		return (-1);
	close(file);

	return (1);
}
