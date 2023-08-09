#include <stdlib.h>

/**
 * _strlen - length of string
 * @s: strin
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
 * argstostr - concacenates arguments
 * @ac: arg count
 * @av: arg vector
 * Return: pointer to string
 */
char *argstostr(int ac, char **av)
{
	int i, j, nc = 0, cmpt = 0;
	char *arg_string;

	if (ac == 0 || av == 0)
		return (NULL);

	for  (i = 0; i < ac; i++, nc++)
		nc += _strlen(av[i]);
	arg_string = malloc(sizeof(char) * nc + 1);
	
	if (arg_string == 0)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, cmpt++)
			arg_string[cmpt] = av[i][j];
		arg_string[cmpt] = '\n';
		cmpt++;
	}
	arg_string[cmpt] = '\0';
	return (arg_string);
}
