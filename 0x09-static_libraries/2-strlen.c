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
