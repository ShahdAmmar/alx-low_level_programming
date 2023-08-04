#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - check string
 * @str: array str
 * Return: 0
 */
int check_num(char *str)
{
	unsigned int count = 0;

	while (count < strlen(str))
	{
		if (!isdigit(str[count]))
		{
			return (0);
		}
		count++;
	}
	return (1);
}
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
		if (check_num(argv[i]))
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
