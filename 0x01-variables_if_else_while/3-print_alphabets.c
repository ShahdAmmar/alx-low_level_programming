#include <stdio.h>

/**
 * main - entry point
 * Descrition: alphabets in lowercase and uppercase
 * Return: 0
 */

int main(void)
{
	char ch1 = 'a';
	char ch2 = 'A';

	while (ch1 <='z')
	{
		putchar(ch1);
		ch1++;
	}
	while (ch2 <='Z')
	{
		putchar(ch2);
		ch2++;
	}
	putchar('\n');
	return (0);
}
