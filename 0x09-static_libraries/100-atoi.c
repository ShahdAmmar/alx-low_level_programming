/**
 * _atoi - string to integer
 * @s: string
 * Return: intger
 */

int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;

	do {
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - 48);
		else if (num > 0)
			break;
	} while (*s++);

	return (num * sign);
}
