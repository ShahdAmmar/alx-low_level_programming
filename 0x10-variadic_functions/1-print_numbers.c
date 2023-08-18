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
	for (i = 0; i < n - 1; i++)
	{
		if (separator == NULL)
			printf("%d", va_arg(args, int));
		else
			printf("%d%s", va_arg(args, int), separator);
	}
	printf("%d\n", va_arg(args, int));
	va_end(args);
}
