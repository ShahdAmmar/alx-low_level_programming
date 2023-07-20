#include "main.h"

/**
 * largest_number - returns largest number
 * @a: 1st integer
 * @b: 2nd integer
 * @c: 3rd integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

	if (a > b && b > c)
	{
		largest = a;
	}
	else if (a > c && c > b)
	{
		largest = a;
	}
	else if (b > a && a > c)
	{
		largest = b;
	}
	else if (b > c && c > a)
	{
		largest = b;
	}
	else
	{
		largest = c;
	}

	return (largest);
}
