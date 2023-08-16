/**
 * array_iterator - iterate through elemnts and perfoem specific func
 * @array: array of int
 * @size: length of array
 * @action: pointer to func
 * Return: void
 */
void array_iterator(int *array, int size, void (*action)(int))
{
	int i;

	if (array && size && action)
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
