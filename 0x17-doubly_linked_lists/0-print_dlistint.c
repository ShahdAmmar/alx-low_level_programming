#include "lists.h"

/**
 * print_dlistint - printing duble list of ints
 * @h: ptr to list
 * Return: No. nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t nd_cnt = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nd_cnt++;
	}
	return (nd_cnt);
}
