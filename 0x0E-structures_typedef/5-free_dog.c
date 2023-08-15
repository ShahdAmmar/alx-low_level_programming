#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - free dog space
 * @d: struct
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d);
		free(d->name);
		free(d->owner);
	}
}
