/**
 * rev_string - reverse string variable
 * @s: string
 * Return: void
 */
void rev_string(char *s)
{
	int count = 0, i = 0;
	char rev = s[0];

	while (s[count] != '\0')
		count++;
	for (i = 0; i < count; i++)
	{
		count--;
		rev = s[i];
		s[i] = s[count];
		s[count] = rev;
	}
}
