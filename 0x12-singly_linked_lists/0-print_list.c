#include <stdio.h>
#include "lists.h"

/**
 * print_list - Displays all elements of a linked list.
 * @h: Pointer to the list_t list to be displayed.
 *
 * Return: Number of nodes displayed.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		count++;
	}

	return (count);
}
