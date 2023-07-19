#include "main.h"

/**
 * main - check code
 * Return: 0
 */

int main(void)
{
	int r;

	print_last_digit(98);
	print_last_digit(0);
	r = print_last_digit(-1024);
	_putchar(r + 48);
	_putchar('\n');
	return (0);
}
