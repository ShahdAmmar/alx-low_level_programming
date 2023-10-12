#include "lists.h"

/**
 * add_dnodeint_end - add node at end of list
 * @head: list
 * @n: value
 * Return: new node or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nd, *new_nd = malloc(sizeof(dlistint_t));

	if (!new_nd)
		return (NULL);
	if (!head || !n)
	{
		free(new_nd);
		return (NULL);
	}

	new_nd->n = n;
	new_nd->next = NULL;
	if (!*head)
	{
		*head = new_nd;
		new_nd->prev = NULL;
	}
	else
	{
		nd = *head;
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
		new_nd->prev = nd;
	}
	return (new_nd);
}
