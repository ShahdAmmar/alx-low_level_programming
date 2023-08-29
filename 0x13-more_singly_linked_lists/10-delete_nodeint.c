#include "lists.h"

/**
 * delete_nodeint_at_index - delete specific node
 * @head: first node
 * @index: specific location
 * Return: 1 or -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp = *head;
	listint_t *current_nd = NULL;

	if (!(*head))
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
	}
	current_nd = temp->next;
	temp->next = current_nd->next;
	free(current_nd);
	return (1);
}
