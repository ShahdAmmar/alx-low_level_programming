#include <stdlib.h>

/**
 * wrdcount - count words in string
 * @s: string
 * Return: No. words
 */
int wrdcount(char *s)
{
	int i, n = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				n++;
		}
		else if (i == 0)
			n++;
	}
	n++;
	return (n);
}

/**
 * strtow - split string into words
 * @str: string
 * Return: pointer to array of words
 */
char **strtow(char *str)
{
	int i, j, k, l, n = 0, wc = 0;
	char **ar;

	if (str == NULL || *str == '\0')
		return (NULL);
	n = wrdcount(str);
	if (n == 1)
		return (NULL);
	ar = (char **)malloc(n * sizeof(char *));
	if (ar == NULL)
		return (NULL);
	ar[n - 1] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			ar[wc] = (char *)malloc(j * sizeof(char));
			j--;
			if (ar[wc] == NULL)
			{
				for (k = 0; k < wc; k++)
					free(ar[k]);
				free(ar[n - 1]);
				free(ar);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				ar[wc][l] = str[i + l];
			ar[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
			i++;
	}
	return (ar);
}

