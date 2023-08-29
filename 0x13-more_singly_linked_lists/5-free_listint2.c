#include "lists.h"

/**
 * free_listint2 - free list and set head to null
 * @head: ptr to head node
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *nxt_nd;

	while ((*head)->next != NULL)
	{
		nxt_nd = (*head)->next;
		free(*head);
		*head = nxt_nd;
	}
	free(*head);
	*head = NULL;
}
