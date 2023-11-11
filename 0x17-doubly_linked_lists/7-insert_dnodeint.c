#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a specified index in a doubly linked list.
 * @h: Pointer to the head of the list.
 * @idx: Index at which to insert the new node.
 * @n: Integer value for the new node.
 *
 * Return: Pointer to the new node, or NULL if insertion fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *current_node = *h, *new_node;

if (idx == 0)
return add_dnodeint(h, n);

while (idx > 1 && current_node != NULL)
{
current_node = current_node->next;
idx--;
}

if (current_node == NULL || (current_node->next == NULL && idx > 0))
return NULL;

if (current_node->next == NULL)
return add_dnodeint_end(h, n);

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
  return (NULL);

new_node->n = n;
new_node->prev = current_node;
new_node->next = current_node->next;
current_node->next->prev = new_node;
current_node->next = new_node;

 return (new_node);
}
