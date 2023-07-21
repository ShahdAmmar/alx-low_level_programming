#include "main.h"

/**
 * print_triangle - print
 * @size: base size
 * Return: void
 */

void print_triangle(int size)
{
	int i, j, k;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			for (k = size - i; k > 1; k--)
			{
				_putchar(32);
			}
			for (j = 0; j <= i; j++)
			{
				_putchar(35);
			}
			_putchar('\n');
		}
	}
	else
		_putchar('\n');
}
