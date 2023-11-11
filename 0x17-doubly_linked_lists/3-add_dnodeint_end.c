#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list.
 * @head: Pointer to the head node of the list.
 * @n: Integer data to store in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *newNode = malloc(sizeof(dlistint_t)), *currentNode;

if (!head || !newNode)
return (newNode ? free(newNode), NULL : NULL);

newNode->n = n;
newNode->next = NULL;
if (!*head)
{
newNode->prev = NULL;
*head = newNode;
}
else
{
currentNode = *head;
while (currentNode->next)
currentNode = currentNode->next;

currentNode->next = newNode;
newNode->prev = currentNode;
}
return (newNode);
}
