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
 * str_concat - concatenate 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: final string
 */
char *str_concat(char *s1, char *s2)
{
	int size1, size2, i;
	char *m;

	if (s1 == NULL)
		s1 = '\0';
	if (s2 == NULL)
		s2 = '\0';

	size1 = _strlen(s1);
	size2 = _strlen(s2);
	m = malloc((size1 + size2 + 1) * sizeof(char));

	if (m == 0)
		return (0);

	for (i = 0; i <= size1 + size2; i++)
	{
		if (i < size1)
			m[i] = s1[i];
		else
			m[i] = s2[i - size1];
	}
	m[i] = '\0';
	return (m);
}
