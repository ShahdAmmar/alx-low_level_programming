#include "lists.h"

/**
 * free_list - free list_t
 * @head: ptr to head node
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *nxt_node;

	while (head)
	{
		nxt_node = head->next;
		free(head->str);
		free(head);
		head = nxt_node;
	}
}
