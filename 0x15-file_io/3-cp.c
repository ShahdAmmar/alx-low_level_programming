#include "main.h"
#define BUFFER_SIZE 1024

/**
 * cr_buff - allocate memory for buffer
 * @file: name of buff file
 * Return: ptr to buff
 */
char *cr_buff(char *file)
{
	char *buff = malloc(sizeof(char) * BUFFER_SIZE);

	if (!buff)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buff);
}

/**
 * close_f - close fd
 * @fildes: fildes shoulf be closed
 * Return: void
 */
void close_f(int fildes)
{
	int closing = close(fildes);

	if (closing == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fildes);
		exit(100);
	}
}

/**
 * main - copy file content into another
 * @argc: arg count
 * @argv: ard vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *buff;
	int fil_from, fil_to, r_data, w_data;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to \n");
		exit(97);
	}

	buff = cr_buff(argv[2]);

	fil_from = open(argv[1], O_RDONLY);
	r_data = read(fil_from, buff, BUFFER_SIZE);
	fil_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	do {
		if (fil_from == -1 || r_data == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}
		w_data = write(fil_to, buff, r_data);
		if (fil_to == -1 || w_data == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}
		r_data = read(fil_from, buff, BUFFER_SIZE);
		fil_to = open(argv[2], O_WRONLY | O_APPEND);
	} while (r_data > 0);

	free(buff);
	close_f(fil_from);
	close_f(fil_to);
	return (0);
}
