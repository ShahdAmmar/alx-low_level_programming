/**
 * *_strcat - append src string to dest string
 * @dest: string
 * @src: source string
 * Return: resulting dest
 */
char *_strcat(char *dest, char *src)
{
	int c1 = 0, c2;

	while (dest[c1])
		c1++;

	for (c2 = 0; src[c2]; c2++)
		dest[c1++] = src[c2];
	return (dest);
}
