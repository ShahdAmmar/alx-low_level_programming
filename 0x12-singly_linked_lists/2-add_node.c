#include "lists.h"

/**
 * add_node - add node at beginning
 * @head: ptr to head node
 * @str: string
 * Return: ptr to new element or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_hd = malloc(sizeof(list_t));

	if (head == NULL || new_hd == NULL)
		return (NULL);

	if (str)
	{
		new_hd->str = strdup(str);
		if (!new_hd->str)
		{
			free(new_hd);
			return (NULL);
		}
		new_hd->len = strlen(new_hd->str);
		new_hd->next = *head;
		*head = new_hd;
	}
	return (new_hd);
}
