#include "hash_tables.h"

/**
 * shash_table_create - creat ht
 * @size: size of ht
 * Return: ht
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *srt_hsh_tbl;

	srt_hsh_tbl = malloc(sizeof(shash_table_t));
	if (srt_hsh_tbl == NULL)
		return (NULL);

	srt_hsh_tbl->size = size;
	srt_hsh_tbl->shead = NULL;
	srt_hsh_tbl->stail = NULL;
	srt_hsh_tbl->array = malloc(size * sizeof(shash_node_t));
	if (srt_hsh_tbl->array == NULL)
	{
		free(srt_hsh_tbl);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		srt_hsh_tbl->array[i] = NULL;

	return (srt_hsh_tbl);
}

/**
 * add_to_srtd_lst - add node to sorted list
 * @ht: hash table
 * @nd: node
 * Return: void
 */
void add_to_srtd_lst(shash_table_t *ht, shash_node_t *nd)
{
	shash_node_t *temp;

	if (ht->shead == NULL && ht->stail == NULL)
	{
		ht->shead = ht->stail = nd;
		return;
	}

	temp = ht->shead;
	while (temp)
	{
		if (strcmp(nd->key, temp->key) < 0)
		{
			nd->snext = temp;
			nd->sprev = temp->sprev;
			temp->sprev = nd;
			if (nd->sprev != NULL)
				nd->sprev->snext = nd;
			else
				ht->shead = nd;
			return;
		}
		temp = temp->snext;
	}
	nd->sprev = ht->stail;
	ht->stail->next = nd;
	ht->stail = nd;
}

/**
 * shash_node_creating - create new node
 * @key: key
 * @value: value of key
 * Return: new node or NULL
 */
shash_node_t *shash_node_creating(const char *key, const char *value)
{
	shash_node_t *snd = malloc(sizeof(shash_node_t));

	if (snd == NULL)
		return (NULL);

	snd->key = strdup(key);
	if (snd->key == NULL)
	{
		free(snd);
		return (NULL);
	}

	snd->value = strdup(value);
	if (snd->value == NULL)
	{
		free(snd->key);
		free(snd);
		return (NULL);
	}
	snd->next = snd->snext = snd->sprev = NULL;
	return (snd);
}

/**
 * shash_table_set - sets value to key
 * @ht: hash table
 * @key: key
 * @value: data
 * Return: 1 or 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_val;
	shash_node_t *srt_hsh_nd, *temp;

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

	srt_hsh_nd = shash_node_creating(key, value);
	if (!srt_hsh_nd)
		return (0);
	srt_hsh_nd->next = ht->array[idx];
	ht->array[idx] = srt_hsh_nd;
	add_to_srtd_lst(ht, srt_hsh_nd);
	return (1);
}

/**
 * shash_table_get - get value for specific key
 * @ht: hash table
 * @key: key
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL || ht->size == 0 || ht->array == NULL ||
			key == NULL || strlen(key) == 0)
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - print hsh table
 * @ht: hash table
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int not_end = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	temp = ht->shead;
	while (temp)
	{
		if (not_end == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		not_end = 1;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print hsh table in reverse
 * @ht: hash table
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	int not_end = 0;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	temp = ht->stail;
	while (temp)
	{
		if (not_end == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		not_end = 1;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete hsh table
 * @ht: hash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *nd, *temp;
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
	ht->size = 0;
	ht->shead = ht->stail = NULL;
	free(ht);
}
