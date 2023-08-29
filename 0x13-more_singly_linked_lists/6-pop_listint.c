#include "lists.h"

/**
 * pop_listint - deletes head node
 * @head: head node
 * Return: head node's data or 0
 */

int pop_listint(listint_t **head)
{
	int h_data;
	listint_t *temp;

	if (!head || !(*head))
		return (0);

	h_data = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (h_data);
}
