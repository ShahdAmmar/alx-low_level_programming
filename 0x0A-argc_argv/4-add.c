#include <stdio.h>
#include <stdlib.h>
/**
 * main - add positive numbers
 * @argc: count
 * @argv: vector
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	int i, sum = 0;

	for (i = 1; i < argc; i++)
	{
		if (*argv[i] >= 48 && *argv[i] <= 57)
		{
			if (atoi(argv[i]) >= 0)
				sum += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}
	printf("%d\n", sum);
	return (0);
}
