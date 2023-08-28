#include "lists.h"

/**
* delete_nodeint_at_index - removes a node in a singly linked list at a 
* specified position
* @head: reference to the starting node of the list
* @index: position of the node to remove
*
* Return: 1 if successful, or -1 if operation fails
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *previousNode = *head;
listint_t *nodeToDelete = NULL;
unsigned int counter = 0;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
free(previousNode);
return (1);
}

while (counter < index - 1)
{
if (!previousNode || !(previousNode->next))
return (-1);
previousNode = previousNode->next;
counter++;
}

nodeToDelete = previousNode->next;
previousNode->next = nodeToDelete->next;
free(nodeToDelete);

return (1);
}
