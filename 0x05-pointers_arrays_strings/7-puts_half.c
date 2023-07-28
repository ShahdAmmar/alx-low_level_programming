#include "main.h"
/**
 * puts_half - print half of trsing
 * @str: string
 * Return: void
 */
void puts_half(char *str)
{
	int count, i;

	for (count = 0; str[count] != '\0'; count++)
		;
	count++;
	/*_putchar(count);*/
	for (i = count / 2; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
