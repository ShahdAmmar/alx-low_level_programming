/**
 * *_strstr - locate 1st occurrence
 * @haystack: where to search
 * @needle: what to search about
 * Return: pointer to beginning of substring or Null
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	char *p;

	while (haystack[i] != '\0')
	{
		if (needle[0] == haystack[i])
		{
			p = &haystack[i];
			return (p);
		}
		i++;
	}
	return (0);
}
