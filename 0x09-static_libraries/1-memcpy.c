/**
 * *_memcpy - copy from src to dest
 * @dest: where string should be copied
 * @src: what to copy
 * @n: No. bytes
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
