/**
 * _abs - absolute
 * @n: number to check
 * Return: number
 */

int _abs(int n)
{
	int abs_n;

	if (n >= 0)
	{
		return (n);
	}
	else
	{
		abs_n = n / -1;
		return (abs_n);
	}
}
