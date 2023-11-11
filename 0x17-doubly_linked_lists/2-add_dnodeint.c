#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list.
 * @head: Pointer to the address of the current head node of the list.
 * @n: The integer data to be added to the new node.
 *
 * This function creates a new node with the given data (`n`) and inserts it at
 * the beginning of the list. The new node becomes the new head of the list.
 *
 * Return: Pointer to the new node, or NULL if the node couldn't be added.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *newNode = malloc(sizeof(dlistint_t));

if (!head || !newNode)
return (newNode ? free(newNode), NULL : NULL);

newNode->n = n;
newNode->prev = NULL;
if (!*head)
{
*head = newNode;
newNode->next = NULL;
}
else
{
newNode->next = *head;
(*head)->prev = newNode;
*head = newNode;
}
return (newNode);
}
