#include "lists.h"

/**
 * add_nodeint_end - add intger new node at the end of the list
 * @head: ptr to first node
 * @n: intger
 * Return: new node or NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_nd = malloc(sizeof(listint_t));
	listint_t *nd = *head;

	if (!head || !new_nd)
		return (NULL);

	new_nd->n = n;
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
	}
	else
		*head = new_nd;
	return (new_nd);
}
