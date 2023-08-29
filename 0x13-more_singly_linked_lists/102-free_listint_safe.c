#include "lists.h"

/**
 * free_list_safe - Frees a looped or non-looped linked list.
 * @head: Reference to the start of the linked list.
 *
 * Return: Number of nodes in the freed list.
 */
size_t free_list_safe(listint_t **head)
{
    size_t node_count = 0;
    int offset;
    listint_t *next_node;

    if (!head || !*head)
        return (0);

    while (*head)
    {
        offset = *head - (*head)->next;
        if (offset > 0)
        {
            next_node = (*head)->next;
            free(*head);
            *head = next_node;
            node_count++;
        }
        else
        {
            free(*head);
            *head = NULL;
            node_count++;
            break;
        }
    }

    *head = NULL;

    return (node_count);
}
