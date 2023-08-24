#include <stdio.h>
#include "lists.h"

/**
 * print_list - Displays all elements of a linked list.
 * @currentNode: Pointer to the list_t list to be displayed.
 *
 * Return: Number of nodes displayed.
 */
size_t print_list(const list_t *currentNode)
{
	size_t count = 0;

	while (currentNode)
	{
		if (!currentNode->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", currentNode->len, currentNode->str);
		currentNode = currentNode->next;
		count++;
	}

	return (count);
}
