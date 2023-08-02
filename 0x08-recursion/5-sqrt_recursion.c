/**
 * _sqrt_recursion - returns natural square root of n if possible
 * @n: number
 * @val: posiible root
 * Return: quare root or -1
 */

int square(int n, int val);

int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 * square - calculate sqaure root
 * @n: number
 * @val: possible root
 * Return: sqaure root or -1
 */
int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);
}
