#include "lists.h"

/**
 * free_list - free list_t
 * @head: ptr to head node
 * 
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *node, *nxt_node;

	node = head;
	while (node)
	{
		nxt_node = node->next;
		free(node->str);
		free(node);
		node = nxt_node;
	}
}
