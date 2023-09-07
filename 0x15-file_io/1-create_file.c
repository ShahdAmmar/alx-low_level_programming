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
 * create_file - create a file which may contains text
 * @filename: name of created file
 * @text_content: text to put in the file
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_content)
{
	int file, slen = 0, w_data;

	if (!filename)
		return (-1);

	if (text_content != NULL)
		slen = _strlen(text_content);

	file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w_data = write(file, text_content, slen);
	if (file == -1 || w_data == -1)
		return (-1);
	close(file);
	return (1);
}
