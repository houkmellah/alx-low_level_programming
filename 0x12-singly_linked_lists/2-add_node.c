#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node to the start of a linked list.
 * @start: Double pointer to the beginning of the list.
 * @inputStr: String to insert into the new node.
 *
 * Return: Address of the new element, or NULL on failure.
 */
list_t *add_node(list_t **start, const char *inputStr)
{
	list_t *newNode;
	unsigned int strLength = 0;

	while (inputStr[strLength])
		strLength++;

	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);

	newNode->str = strdup(inputStr);
	newNode->len = strLength;
	newNode->next = (*start);
	(*start) = newNode;

	return (*start);
}
