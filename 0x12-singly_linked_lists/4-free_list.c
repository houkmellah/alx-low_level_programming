#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Releases memory of a linked list.
 * @start: The starting node of the list_t list to be freed.
 */
void free_list(list_t *start)
{
	list_t *currentNode;

	while (start)
	{
		currentNode = start->next;
		free(start->str);
		free(start);
		start = currentNode;
	}
}
