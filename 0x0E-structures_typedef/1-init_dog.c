#include "dog.h"

/**
 * init_dog - intiate struct dog
 * @d: address
 * @name: dog name
 * @age: dog age
 * @owner: owner name
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
