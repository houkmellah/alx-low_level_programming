#include "lists.h"

/**
 * print_dlistint - Prints the 'n' value of each node in a doubly-linked list.
 * @h: Pointer to the head node of the list.
 *
 * Return: Number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
size_t count = 0;

while (h)
{
printf("%d\n", h->n);
h = h->next;
count++;
}
return (count);
}
