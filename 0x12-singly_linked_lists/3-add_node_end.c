#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node to the end of a linked list.
 * @start: Double pointer to the start of the list.
 * @inputStr: String to be added to the new node.
 *
 * Return: Address of the new element or NULL if creation failed.
 */
list_t *add_node_end(list_t **start, const char *inputStr)
{
	list_t *newNode;
	list_t *currentNode = *start;
	unsigned int strLength = 0;

	while (inputStr[strLength])
		strLength++;

	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);

	newNode->str = strdup(inputStr);
	newNode->len = strLength;
	newNode->next = NULL;

	if (*start == NULL)
	{
		*start = newNode;
		return (newNode);
	}

	while (currentNode->next)
		currentNode = currentNode->next;

	currentNode->next = newNode;

	return (newNode);
}
