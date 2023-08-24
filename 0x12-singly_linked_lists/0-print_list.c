#include "lists.h"

/**
 * print_list - print string and its length
 * @h: head of list
 * Return: length of string
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str != NULL)
			printf("[%ld] %s\n", strlen(h->str), h->str);
		else
			printf("[0] (nil)\n");
		h = h->next;
		nodes++;
	}
	return (nodes);
}
