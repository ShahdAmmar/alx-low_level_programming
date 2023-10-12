#include "lists.h"

/**
 * dlistint_len - determine No. elements
 * @h: ptr to list
 * Return: No. nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t nd_cnt = 0;

	while (h)
	{
		h = h->next;
		nd_cnt++;
	}
	return (nd_cnt);
}
