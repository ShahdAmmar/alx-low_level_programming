#include "lists.h"

/**
 * get_dnodeint_at_index - return specific node
 * @head: linked list
 * @index: position
 * Return: node or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int cnt = 0;

	while (head)
	{
		if (cnt == index)
			return (head);
		head = head->next;
		cnt++;
	}
	return (NULL);
}
