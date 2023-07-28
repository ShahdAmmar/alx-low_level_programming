#include "main.h"
/**
 * puts_half - print half of trsing
 * @str: string
 * Return: void
 */
void puts_half(char *str)
{
	int count = 0, i;

	while (str[count] != '\0')
		count++;
	for (i = count / 2; i < count; i++)
		_putchar(str[i]);
	_putchar('\n');
}
