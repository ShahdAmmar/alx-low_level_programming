#include <stdlib.h>
/**
 * create_array - create array of char
 * @size: array length
 * @c: starting char
 * Return: 0 or pointer or null
 */
char *create_array(unsigned int size, char c)
{
	char *ar;

	if (size == 0)
		return (NULL);
	ar = malloc(sizeof(char) * size);
	ar[0] = c;
	return (ar);
}
