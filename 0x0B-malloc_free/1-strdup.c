#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a copied string
 * @str: given string
 * Return: pointer or NULL
 */
char *_strdup(char *str)
{
	int len = _strlen(str);
	char *copy = malloc(len);
	int i;

	if (len == 0 || copy == 0)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	return (copy);
}
