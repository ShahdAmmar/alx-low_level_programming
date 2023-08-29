#include "lists.h"

/**
 * add_nodeint - add node at the beginning
 * @head: head
 * @n: intger
 * Return: address of new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_hd = malloc(sizeof(listint_t));

	if (!head || !new_hd)
		return (NULL);

	if (n)
	{
		new_hd->n = n;
		new_hd->next = *head;
		*head = new_hd;
	}
	return (new_hd);
}
