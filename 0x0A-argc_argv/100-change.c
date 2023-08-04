#include <stdio.h>
#include <stdlib.h>
/**
 * main - min mun of coins to change for amout of money
 * @argc: count
 * @argv: vector
 * Return: 0 or 1
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i, leastcoins = 0, money = atoi(argv[1]);
		int cents[] = {25, 10, 5, 2, 1};

		for (i = 0; i < 5; i++)
		{
			if (money >= cents[i])
			{
				leastcoins += money / cents[i];
				money %= cents[i];
				if (money == 0)
					break;
			}
		}
		printf("%d\n", leastcoins);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}	
