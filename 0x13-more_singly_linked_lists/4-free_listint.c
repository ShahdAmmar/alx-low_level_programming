#include "lists.h"

/**
 * free_listint - free list of intgers
 * @head: ptr to first node
 * Return: void
 */

void free_listint(listint_t *head)
{
	listint_t *nxt_nd;

	while (head)
	{
		nxt_nd = head->next;
		free(head);
		head = nxt_nd;
	}
}
