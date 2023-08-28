#include "lists.h"

/**
* get_nodeint_at_index - fetches the node at a specific index in a singly list
* @head: starting node of the list
* @index: position of the node to fetch
*
* Return: reference to the desired node, or NULL if not found
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int counter = 0;
listint_t *currentNode = head;

while (currentNode && counter < index)
{
currentNode = currentNode->next;
counter++;
}

return (currentNode ? currentNode : NULL);
}
