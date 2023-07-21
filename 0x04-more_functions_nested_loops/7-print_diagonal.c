#include "main.h"

/**
 * print_diagonal - print _
 * @n: no. of _
 * Return: void
 */

void print_diagonal(int n)
{
	int i;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			_putchar('\\');
		}
	}
	_putchar('\n');
}
