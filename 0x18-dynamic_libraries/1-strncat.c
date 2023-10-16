/**
 * *_strncat - concantenate n bytes
 * @dest: where the strings should be concatenated
 * @src: source string
 * @n: No. bytes
 * Return: resulting dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int c1 = 0, c2;

	while (dest[c1])
		c1++;
	for (c2 = 0; c2 < n && src[c2] != '\0'; c2++)
		dest[c1++] = src[c2];
	return (dest);
}
