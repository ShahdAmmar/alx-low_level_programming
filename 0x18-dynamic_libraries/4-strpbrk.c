/**
 * *_strpbrk - locates first occurence
 * @s: where to search
 * @accept: what to search about
 * Return: pointer to bytes in s
 */
char  *_strpbrk(char *s, char *accept)
{
	int i = 0, j;
	char *p;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
				p = &s[i];
				return (p);
			}
			j++;
		}
		i++;
	}
	return (0);
}
