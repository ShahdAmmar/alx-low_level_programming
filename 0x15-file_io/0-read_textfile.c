#include "main.h"

/**
 * read_textfile - read file, then print to std output
 * @filename: name of textfile
 * @letters: No. letter to print
 * Return: actual No. printed letters ot NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file, r_data, w_data;
	char *buffer;

	if (!filename || !letters)
		return (0);

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	r_data = read(file, buffer, letters);
	w_data = write(STDOUT_FILENO, buffer, r_data);
	free(buffer);
	close(file);

	return (w_data);
}
