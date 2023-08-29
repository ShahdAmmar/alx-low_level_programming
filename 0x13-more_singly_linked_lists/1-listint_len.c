#include "lists.h"

/**
 * listint_len - returns length of list
 * @h: ptr to head
 * Return: No. nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
