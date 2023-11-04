#include "hash_tables.h"

/**
 * hash_table_print - print hsh table
 * @ht: hash table
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int i;
	int not_end = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp)
		{
			if (not_end == 1)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			not_end = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
