#include <stdlib.h>
/**
 * **alloc_grid - create 2-d array
 * @width: width of array
 * @height: height of array
 * Return: array
 */
int **alloc_grid(int width, int height)
{
	int **ar, i, j;

	ar = malloc(sizeof(*ar) * height);

	if (width <= 0 || height <= 0 || ar == 0)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		ar[i] = malloc(sizeof(**ar) * width);
		if (ar[i] == 0)
		{
			while (i--)
				free(ar[i]);
			free(ar);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			ar[i][j] = 0;
	}
	return (ar);
}
