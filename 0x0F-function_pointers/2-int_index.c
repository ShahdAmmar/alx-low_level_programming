/**
 * int_index - return index of specific num
 * @array: array of int
 * @size: length of array
 * @cmp: func
 * Return: index of -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && size && cmp)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) == 1)
				return (i);
		}
	}
	return (-1);
}
