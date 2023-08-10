#include <stdlib.h>

/**
 * array_range - create array of intgers in specific range
 * @min: minimum value
 * @max: maximum value
 * Return: pointer to array
 */
int *array_range(int min, int max)
{
	int *ar, i, len;

	if (min > max)
		return (NULL);
	len = max - min + 1;
	ar = malloc(len * sizeof(int));
	if (ar == 0)
		return (NULL);

	for (i = 0; i < len; i++)
		ar[i] = min++;
	return (ar);
}
