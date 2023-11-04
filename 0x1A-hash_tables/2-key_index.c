#include "hash_tables.h"
/**
 * key_index - returns index using djb2
 * @key: key
 * @size: size of hsh array
 * Return: index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx = hash_djb2(key) % size;

	return (idx);
}
