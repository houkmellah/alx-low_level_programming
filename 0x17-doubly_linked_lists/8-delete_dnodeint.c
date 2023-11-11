#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given index from a doubly linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 upon success, or -1 if the deletion fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current_node = *head;

if (*head == NULL)
return (-1);
 
while (index > 0 && current_node != NULL)
{
current_node = current_node->next;
index--;
}

if (current_node == NULL)
return (-1);

if (current_node == *head)
{
*head = current_node->next;
if (*head != NULL)
(*head)->prev = NULL;
}
else
{
if (current_node->next != NULL)
current_node->next->prev = current_node->prev;

if (current_node->prev != NULL)
current_node->prev->next = current_node->next;
}

free(current_node);
return (1);
}
