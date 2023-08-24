#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Counts the elements in a linked list.
 * @head: Pointer to the beginning of the list.
 *
 * Return: Total number of elements.
 */
size_t list_len(const list_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
