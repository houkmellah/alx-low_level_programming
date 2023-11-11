#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: None.
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *currentNode;

while (head)
{
currentNode = head;
head = head->next;
free(currentNode);
}
}
