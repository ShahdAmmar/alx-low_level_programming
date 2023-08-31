/**
 * get_endianness - determine if endianness is little or big
 * Return: 0 if big or 1 if little
 */
int get_endianness(void)
{
	unsigned long int x = 1;
	char *c = (char *) &x;

	return (*c);
}
