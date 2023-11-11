#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves a node at a specified index in a list.
 * @head: Pointer to the head node of the list.
 * @index: The index of the node to retrieve.
 *
 * Return: Pointer to the node at the specified index, or NULL if not found.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int currentIndex = 0;

while (head)
{
if (currentIndex == index)
return head;
head = head->next;
currentIndex++;
}
return NULL;
}
