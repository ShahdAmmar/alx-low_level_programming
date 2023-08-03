/**
 * is_palindrome - returns if string is palindrome or not
 * @s: string
 * Return: 1 or 0
 */
int lastindex(char *s);
int check(char *s, int start, int end, int mod);
int is_palindrome(char *s)
{
	int end = lastindex(s);

	return (check(s, 0, end - 1, end % 2));
}
/**
 * lastindex - determine length of string
 * @s: string
 * Return: length
 */
int lastindex(char *s)
{
	int n = 0;

	if (*s > '\0')
		n += lastindex(s + 1) + 1;
	return (n);
}
/**
 * check - check letters of string
 * @s: string
 * @start: start index
 * @end: last letter index
 * @mod: modulus of index
 * Return: 1 or 0
 */
int check(char *s, int start, int end, int mod)
{
	if ((start == end && mod != 0)
		|| (start == end + 1 && mod == 0))
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (check(s, start + 1, end - 1, mod));
	return (0);
}
