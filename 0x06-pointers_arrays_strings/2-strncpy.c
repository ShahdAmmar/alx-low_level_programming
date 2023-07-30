/**
 * *_strncpy - copy n bytes
 * @dest: where the string is copied
 * @src: what should be copied
 * @n: No. bytes
 * Return: resulting dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int c;

	for (c = 0; c < n && src[c] != '\0'; c++)
		dest[c] = src[c];
	if (c < n)
		dest[c] = '\0';
	return (dest);
}
