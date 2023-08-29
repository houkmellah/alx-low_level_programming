#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Determines the number of distinct nodes 
 *                      in a possibly circular listint_t linked list.
 * @head: The starting node of the listint_t list.
 *
 * Return: If there's no loop, returns 0.
 *         Otherwise, returns the count of distinct nodes in the loop.
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
 * print_listint_safe - Safely prints the nodes of a listint_t list.
 * @head: The first node of the listint_t list.
 *
 * Return: The total number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t total_nodes, current_index = 0;

total_nodes = looped_listint_len(head);

if (total_nodes == 0)
{
for (; head != NULL; total_nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}

else
{
for (current_index = 0; current_index < total_nodes; current_index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (total_nodes);
}
