#include "lists.h"

/**
 * sum_listint - sum list members
 * @head: ptr to first node
 * Return: sum or 0
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (!head)
		return (0);

	while (head)
	{
		if (head->n)
			sum += head->n;

		head = head->next;
	}
	return (sum);
}
