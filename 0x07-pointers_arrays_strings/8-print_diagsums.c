#include <stdio.h>
/**
 * print_diagsums - print sume od two diagonals of square matrix
 * @a: sqaure matrix
 * @size: size
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i];
		sum2 += a[size - i - 1];
		a += size;
	}
	printf("%d, %d\n", sum1, sum2);
}
