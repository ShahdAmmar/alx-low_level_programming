#include "lists.h"

/**
 * insert_dnodeint_at_index - insert new node at index
 * @h: list
 * @idx: index
 * @n: value
 * Return: new node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_nd, *temp = *h;

	if (idx == 0)
	{
		new_nd = add_dnodeint(h, n);
		return (new_nd);
	}

	while (idx != 1)
	{
		temp = temp->next;
		if (temp == NULL)
			return (NULL);
		idx--;
	}
	if (temp->next == NULL)
	{
		new_nd = add_dnodeint_end(h, n);
		return (new_nd);
	}

	new_nd = malloc(sizeof(dlistint_t));
	if (!new_nd)
		return (NULL);
	new_nd->n = n;
	new_nd->prev = temp;
	new_nd->next = temp->next;
	temp->next->prev = new_nd;
	temp->next = new_nd;
	return (new_nd);
}
