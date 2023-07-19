#include "main.h"

/**
 * print_last_digit - last digit
 * @n: number
 * Return: digit
 */

int print_last_digit(int n)
{
	int digit;

	if (n >= 0)
	{
		digit = n % 10;
		_putchar(digit + 48);
		return (digit);
	}
	else
	{
		digit = (n / -1) % 10;
		_putchar(digit + 48);
		return (digit);
	}
}
