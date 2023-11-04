#include "hash_tables.h"

/**
 * hash_table_delete - delete hsh table
 * @ht: hash table
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *nd, *temp;
	unsigned long int i;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	for (i = 0; i < ht->size; i++)
	{
		nd = ht->array[i];
		while (nd)
		{
			temp = nd->next;
			free(nd->key);
			free(nd->value);
			free(nd);
			nd = temp;
		}
	}
	free(ht->array);
/*
 *	ht->array = NULL;
 *	ht->size = 0;
	*/
	free(ht);
}
