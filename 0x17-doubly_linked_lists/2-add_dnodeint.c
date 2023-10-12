#include "lists.h"

/**
 * add_dnodeint - add node at start of list
 * @head: ptr to list
 * @n: value
 * Return: ptr to new node or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_nd = malloc(sizeof(dlistint_t));

	if (!head || !n)
	{
		free(new_nd);
		return (NULL);
	}

	new_nd->n = n;
	new_nd->prev = NULL;
	if (!*head)
	{
		*head = new_nd;
		new_nd->next = NULL;
	}
	else
	{
		new_nd->next = *head;
		(*head)->prev = new_nd;
		*head = new_nd;
	}

	return (new_nd);
}
