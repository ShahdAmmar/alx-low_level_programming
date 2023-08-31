/**
 * flip_bits - number of bits needed to flip from num to another
 * @n: decimal num
 * @m: decimal num
 * Return: No. flips
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xorop = n ^ m;
	unsigned int count = 0;

	while (xorop)
	{
		if (xorop & 1ul)
			count++;
		xorop = xorop >> 1;
	}
	return (count);
}
