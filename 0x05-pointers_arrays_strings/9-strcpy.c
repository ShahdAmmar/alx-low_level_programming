/**
 * *_strcpy - copy string
 * @dest: where should the string be copied
 * @src: the string should be copied
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	return (dest);
}
