/**
 * *_strstr - locate 1st occurrence
 * @haystack: where to search
 * @needle: what to search about
 * Return: pointer to beginning of substring or Null
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = haystack;
		char *two = needle;

		while (*one == *two && *two != '\0')
		{
			one++;
			two++;
		}
		if (*two == '\0')
			return (haystack);
	}
	return (0);
}
