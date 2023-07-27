#include "main.h"
/**
 * print_rev - print string reversely
 * @s: string
 * Return: void
 */
void print_rev(char *s)
{
	int slen = 0;
	int c = 0;

	while (*s != '\0')
	{
		slen++;
		s++;
	}
	s--;
	for (c = slen; c > 0; c++)
	{
		_putchar(*s);
		s--;
	}
	_putchar('\n')
