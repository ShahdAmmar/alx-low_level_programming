#include <stdlib.h>

/**
 * array_range - create array of intgers in specific range
 * @min: minimum value
 * @max: maximum value
 * Return: pointer to array
 */
int *array_range(int min, int max)
{
	int *ar, i;

	if (min > max)
		return (NULL);

	ar = malloc((max - min + 1) * sizeof(int));
	if (ar == 0)
		return (NULL);

	for (i = min; i <= max; i++)
		ar[i] = i;
	return (ar);
}
