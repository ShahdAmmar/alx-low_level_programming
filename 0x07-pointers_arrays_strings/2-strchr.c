/**
 * *_strchr - search for char
 * @s: string array
 * @c: char
 * Return: 1st occurence
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return ('\0');
}
