#include "lists.h"

/**
 * free_listint_safe - Releases a potentially looped linked list.
 * @h: Address to the pointer of the first node in the linked list.
 *
 * Return: Count of elements in the released list.
 */
size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
int distance;
listint_t *next_node;

if (!h || !*h)
return (0);

while (*h)
{
distance = *h - (*h)->next;
if (distance > 0)
{
next_node = (*h)->next;
free(*h);
*h = next_node;
count++;
}
else
{
free(*h);
*h = NULL;
count++;
break;
}
}

*h = NULL;

return (count);
}
