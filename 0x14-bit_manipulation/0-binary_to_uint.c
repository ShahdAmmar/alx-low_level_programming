/**
 * binary_to_uint - convert binary to unsigned intger
 * @b: string of numbers
 * Return: unsigned int or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		number = number * 2 + (*b - '0');
		b++;
	}
	return (number);
}
