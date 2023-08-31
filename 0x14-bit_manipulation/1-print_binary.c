#include "main.h"

/**
 * print_binary - print binary of given decimal number
 * @n: decimal number
 * Return: void
 */
void print_binary(unsigned long int n)
{
	int count = 0;
	int bits = sizeof(n) * 8;

	while (bits)
	{
		if (n & 1L << --bits)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
