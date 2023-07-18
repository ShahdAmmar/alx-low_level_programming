#include "main.h"
#include <stdio.h>

/**
 * print_alphabet_x10 - write alphabet 10 times
 * Return: void
 */

void print_alphabet_x10(void)
{
	char ch = 'a';
	int i = 0;

	while (i <= 9)
	{
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
