#include <stdio.h>

/**
 * main - entry point
 * Description: alphabets
 * Return: always zero
 */

int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}
	putchar('\n');
	return (0);
}
