#include "lists.h"

/**
 * insert_nodeint_at_index - insert node at specific position
 * @head: first node
 * @idx: index
 * @n: intger
 * Return: new node or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new_nd = malloc(sizeof(listint_t));
	listint_t *node = *head;

	if (!head || !new_nd)
		return (NULL);

	new_nd->n = n;
	new_nd->next = NULL;

	if (idx == 0)
	{
		new_nd->next = *head;
		*head = new_nd;
		return (new_nd);
	}
	for (i = 0; node && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new_nd->next = node->next;
			node->next = new_nd;
			return (new_nd);
		}
		else
			node = node->next;
	}
	return (NULL);
}
