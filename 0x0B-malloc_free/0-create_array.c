#include <stdlib.h>
/**
 * create_array - create array of char
 * @size: array length
 * @c: starting char
 * Return: 0 or pointer or null
 */
char *create_array(unsigned int size, char c)
{
	char *ar = malloc(sizeof(char) * size);

	if (size == 0 || ar == 0)
		return (NULL);
	while (size--)
		ar[size] = c;
	return (ar);
}
