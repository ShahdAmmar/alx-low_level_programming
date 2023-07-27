/**
 * swap_int - switch values
 * @a: 1st int
 * @b: 2nd int
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int first = *a;
	int second = *b;

	*a = second;
	*b = first;
}

