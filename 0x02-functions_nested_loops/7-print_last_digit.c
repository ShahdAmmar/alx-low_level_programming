#include "main.h"

/**
 * print_last_digit - last digit
 * @n: number
 * Return: digit
 */

int print_last_digit(int n)
{
	int digit;

	digit = n % 10;
	if (digit < 0)
	{
		digit *= -1;
	}
	_putchar(digit + 48);
	return (digit);
}
