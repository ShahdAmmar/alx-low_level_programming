#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * new_dog - create new dog
 * @name: dog name
 * @age: dog age
 * @owner: owner name
 * Return: NULL or dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ddog;

	ddog = malloc(sizeof(dog_t));
	if (ddog == NULL)
		return (NULL);

	ddog->name = name;
	ddog->age = age;
	ddog->owner = owner;

	return (ddog);
}
