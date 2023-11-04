#include "hash_tables.h"

/**
 * hash_table_create - creat ht
 * @size: size of ht
 * Return: ht
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hsh_tbl;

	hsh_tbl = malloc(sizeof(hash_table_t));
	if (hsh_tbl == NULL)
		return (NULL);

	hsh_tbl->size = size;
	hsh_tbl->array = malloc(size * sizeof(hash_node_t *));
	if (hsh_tbl->array == NULL)
	{
		free(hsh_tbl);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hsh_tbl->array[i] = NULL;

	return (hsh_tbl);
}
