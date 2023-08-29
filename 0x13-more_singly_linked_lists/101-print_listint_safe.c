#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t  print_listint_safe(const listint_t *head);

/**
* looped_listint_len - Measures unique nodes in a looped linked list.
* @head: Reference to the start of the linked list.
*
* Return: If the list isn't looped - 0.
* Otherwise - the number of unique nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *slow_ptr, *fast_ptr;
size_t node_count = 1;

if (head == NULL || head->next == NULL)
return (0);

slow_ptr = head->next;
fast_ptr = (head->next)->next;

while (fast_ptr)
{
if (slow_ptr == fast_ptr)
{
slow_ptr = head;
while (slow_ptr != fast_ptr)
{
node_count++;
slow_ptr = slow_ptr->next;
fast_ptr = fast_ptr->next;
}

slow_ptr = slow_ptr->next;
while (slow_ptr != fast_ptr)
{
node_count++;
slow_ptr = slow_ptr->next;
}

return (node_count);
}

slow_ptr = slow_ptr->next;
fast_ptr = (fast_ptr->next)->next;
}

return (0);
}

/**
* print_list_safe - Safely prints a linked list.
* @head: Reference to the start of the linked list.
*
* Return: The number of nodes in the list.
*/
size_t  print_listint_safe(const listint_t *head)
{
size_t nodes, i = 0;

nodes = measure_loop_length(head);

if (nodes == 0)
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (i = 0; i < nodes; i++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (nodes);
}
