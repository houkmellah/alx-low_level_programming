#include "lists.h"

/**
 * dlistint_len - Calculates the length of a doubly linked list.
 * @h: Pointer to the head node of the list.
 *
 * This function iterates through each node of a doubly linked list
 * starting from the head node and counts the number of nodes.
 *
 * Return: The total number of nodes in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t length = 0;

while (h)
{
h = h->next;
length++;
}
return length;
}
