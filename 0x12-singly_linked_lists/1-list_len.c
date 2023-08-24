#include "lists.h"

/**
 * list_len - print string and its length
 * @h: head of list
 * Return: No. nodes
 */
size_t list_len(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
