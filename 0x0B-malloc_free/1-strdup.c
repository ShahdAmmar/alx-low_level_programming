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
 * _strdup - returns a pointer to a copied string
 * @str: given string
 * Return: pointer or NULL
 */
char *_strdup(char *str)
{
	int len = _strlen(str);
	char *copy = malloc(len * sizeof(*str) + 1);
	int i;

	if (copy == 0)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	return (copy);
}
