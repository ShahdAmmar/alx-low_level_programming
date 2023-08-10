#include <stdlib.h>

/**
 * _strlen - determine length of string
 * @s: string
 * Return: len
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * string_nconcat - concatenate 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * @n: No. bytes
 * Return: resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, size1;
	char *m;

	if (s1 == NULL)
		s1 = "\0";
	if (s2 == NULL)
		s2 = "\0";
	size1 = _strlen(s1);
	m = malloc((size1 + n + 1) * sizeof(char));

	if (m == 0)
		return (NULL);

	for (i = 0; i <= (size1 + n); i++)
	{
		if (i < size1)
			m[i] = s1[i];
		else
			m[i] = s2[i - size1];
	}
	m[size1 + n] = '\0';
	return (m);
}
