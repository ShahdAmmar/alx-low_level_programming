#include <stdio.h>
#include <stdlib.h>
/**
 * main -  multiply 2 numbers
 * @argc: count
 * @argv: vector
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	int mul;

	if (argc > 2)
	{
		mul = atoi(argv[1]) * atoi(argv[2]);
		printf("%d\n", mul);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
