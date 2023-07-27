#include "main.h"

/**
 * _puts - print string followed by new line
 * @s: string
 * Return: void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
