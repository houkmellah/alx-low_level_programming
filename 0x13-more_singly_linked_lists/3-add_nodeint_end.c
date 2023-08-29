#include "lists.h"

/**
 * add_nodeint_end - appends a node to end of linked list
 * @head: pointer to list's initial node
 * @n: data for new node
 *
 * Return: pointer to appended node, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *last_node = *head;

new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

while (last_node->next)
last_node = last_node->next;

last_node->next = new_node;

return (new_node);
}

