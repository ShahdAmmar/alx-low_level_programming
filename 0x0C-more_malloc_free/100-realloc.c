#include <stdlib.h>

/**
 * _realloc - reallocate
 * @ptr: pointer to previous allocated memory
 * @old_size: size of previous allocation
 * @new_size: size of new allocation
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *rm;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		rm = malloc(new_size);
		if (rm == NULL)
			return (NULL);
		return (rm);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		rm = malloc(new_size);
		if (rm == NULL)
			return (NULL);
		for (i = 0; i < old_size && i < new_size; i++)
			*((char *)rm + i) = *((char *)ptr + i);
		free(ptr);
	}
	return (rm);
}
