#include "main.h"

/**
 * read_textfile - read file and print it to standard output
 * @filename: file
 * @letters: number of letters
 * Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fildes;
	ssize_t bytes;
	char buffer[READ_BUFS * 8];

	if (!filename || !letters)
		return (0);

	fildes = open(filename, 'r');
	if (fildes == -1)
		return (0);
	bytes = read(fildes, &buffer[0], letters);
	bytes = write(1, &buffer[0], bytes);
	close(fildes);

	return (bytes);
}
