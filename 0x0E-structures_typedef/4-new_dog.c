#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int slen = 0;

	while (*s != '\0')
	{
		slen++;
		s++;
	}
	return (slen);
}

/**
 * *_strcpy - copy string
 * @dest: where should the string be copied
 * @src: the string should be copied
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

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
	int len1, len2;

	len1 = _strlen(name);
	len2 = _strlen(owner);

	ddog = malloc(sizeof(dog_t));
	if (ddog == NULL)
		return (NULL);

	ddog->name = malloc(sizeof(char) * (len1 + 1));
	if (ddog->name == NULL)
	{
		free(ddog);
		return (NULL);
	}
	ddog->owner = malloc(sizeof(char) * (len2 + 1));
	if (ddog->owner == NULL)
	{
		free(ddog);
		free(ddog->name);
		return (NULL);
	}
	_strcpy(ddog->name, name);
	_strcpy(ddog->owner, owner);
	ddog->age = age;

	return (ddog);
}
