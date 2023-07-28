#include "main.h"
/**
 * puts2 - print each 2 char
 * @str: string
 * Return: void
 */
void puts2(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str += 2;
	}
	_putchar('\n');
}
