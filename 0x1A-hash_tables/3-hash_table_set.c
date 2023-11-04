#include "hash_tables.h"

/**
 * hash_node_creating - create new node
 * @key: key
 * @value: value of key
 * Return: new node or NULL
 */
hash_node_t *hash_node_creating(const char *key, const char *value)
{
	hash_node_t *nd = malloc(sizeof(hash_node_t));

	if (nd == NULL)
		return (NULL);

	nd->key = strdup(key);
	if (nd->key == NULL)
	{
		free(nd);
		return (NULL);
	}

	nd->value = strdup(value);
	if (nd->value == NULL)
	{
		free(nd->key);
		free(nd);
		return (NULL);
	}
	nd->next = NULL;
	return (nd);
}

/**
 * hash_table_set - sets value to key
 * @ht: hash table
 * @key: key
 * @value: data
 * Return: 1 or 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_val;
	hash_node_t *hsh_nd, *temp;

	if (ht == NULL || ht->size == 0 || ht->array == NULL || key == NULL ||
		       strlen(key) == 0 || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_val = strdup(value);
			if (new_val == NULL)
				return (0);
			free(temp->value);
			temp->value = new_val;
			return (1);
		}
		temp = temp->next;
	}

	hsh_nd = hash_node_creating(key, value);
	if (!hsh_nd)
		return (0);
	hsh_nd->next = ht->array[idx];
	ht->array[idx] = hsh_nd;
	return (1);
}
