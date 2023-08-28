#include "lists.h"

/**
 * listint_len - counts elements in a singly linked list
 * @h: linked list of type listint_t to traverse
 *
 * Return: count of nodes
 */
size_t listint_len(const listint_t *h)
{
    size_t nodeCount = 0;
    
    const listint_t *currentNode = h;

    while (currentNode)
    {
        nodeCount++;
        currentNode = currentNode->next;
    }

    return (nodeCount);
}
