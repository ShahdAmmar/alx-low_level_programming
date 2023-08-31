/**
 * get_bit - get bit value at a given index
 * @n: decimal number
 * @index: index 
 * Return: bit value or -1
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	return (n >> index & 1);
}
