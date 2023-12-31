#include "lists.h"

/**
 * add_node_end - add node at the end
 * @head: ptr to head node
 * @str: string
 * Return: ptr to new elment or NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_nd = malloc(sizeof(list_t));
	list_t *nd = *head;

	if (head == NULL || new_nd == NULL)
		return (NULL);
	if (str)
	{
		new_nd->str = strdup(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
		new_nd->len = strlen(new_nd->str);
	}
	if (nd)
	{
		while (nd->next != NULL)
			nd = nd->next;
		nd->next = new_nd;
	}
	else
		*head = new_nd;
	return (new_nd);
}
