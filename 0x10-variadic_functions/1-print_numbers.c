#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print numbers given as arguments
 * @separator: what is printed bet numbers
 * @n: number of optional args
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));
		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
