/**
 * is_prime_number - determine if n is prime or not
 * @n: integer
 * @othern: helping num
 * Return: 1 or 0
 */
int check_if_prime(int n, int othern);
int is_prime_number(int n)
{
	return (check_if_prime(n, 2));
}

/**
 * check_if_prime - check for prime num
 * @n: num
 * @othern: helping num
 * Return: 0 or 1
 */
int check_if_prime(int n, int othern)
{
	if (othern >= n && n > 1)
		return (1);
	else if (n % othern == 0 || n <= 1)
		return (0);
	else
		return (check_if_prime(n, othern + 1));
}
