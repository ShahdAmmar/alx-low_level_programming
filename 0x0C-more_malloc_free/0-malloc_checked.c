#include <stdlib.h>

/**
 * malloc_checked - check return value of malloc
 * @b: No. bytes
 * Return: pointer
 */
void *malloc_checked(unsigned int b)
{
	int *m = malloc(b);

	if (m == 0)
		exit(98);

	return (m);
}
