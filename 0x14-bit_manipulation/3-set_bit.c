/**
 * set_bit - set specific index to 1
 * @n: decimal number
 * @index: specific indwx
 * Return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	*n = (1 << index) | *n;
	return (1);
}
