#include <stdlib.h>

/**
 * _memset - fill memory
 * @s: pointer
 * @b: constant
 * @n: max. bytes
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _calloc - alloc of array
 * @nmemb: array elements
 * @size: size of each element
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *m;

	if (size == 0 || nmemb == 0)
		return (NULL);

	m = malloc(nmemb * size);
	if (m == 0)
		return (NULL);
	_memset(m, 0, nmemb * size);
	return (m);
}
