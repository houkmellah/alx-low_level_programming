#include "lists.h"

/**
* insert_nodeint_at_index - adds a new node in a singly linked list at a 
* specified position
* @head: reference to the starting node of the list
* @idx: position where the new node should be added
* @n: value to insert in the new node
*
* Return: reference to the new node, or NULL if operation fails
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int counter;
listint_t *newNode;
listint_t *currentNode = *head;

newNode = malloc(sizeof(listint_t));
if (!newNode || !head)
return (NULL);

newNode->n = n;
newNode->next = NULL;

if (idx == 0)
{
newNode->next = *head;
*head = newNode;
return (newNode);
}

for (counter = 0; currentNode && counter < idx; counter++)
{
if (counter == idx - 1)
{
newNode->next = currentNode->next;
currentNode->next = newNode;
return (newNode);
}
else
currentNode = currentNode->next;
}

return (NULL);
}
