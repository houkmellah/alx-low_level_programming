#include "lists.h"

/**
 * free_list_safe - Frees a looped or non-looped linked list.
 * @head: Reference to the start of the linked list.
 *
 * Return: Number of nodes in the freed list.
 */
size_t free_list_safe(listint_t **h)
{
    size_t node_count = 0;
    int offset;
    listint_t *next_node;

    if (!h || !*h)
        return (0);

    while (*h)
    {
        offset = *h - (*h)->next;
        if (offset > 0)
        {
            next_node = (*)->next;
            free(*h);
            *h = next_node;
            node_count++;
        }
        else
        {
            free(*h);
            *h = NULL;
            node_count++;
            break;
        }
    }

    *h = NULL;

    return (node_count);
}
