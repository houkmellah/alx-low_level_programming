#include "lists.h"

/**
 * print_listint - displays elements of a singly linked list
 * @h: singly linked list of type listint_t to display
 *
 * Return: count of nodes
 */
size_t print_listint(const listint_t *h)
{
    size_t nodeCount = 0;
    
    const listint_t *currentNode = h;

    while (currentNode)
    {
        printf("%d\n", currentNode->n);
        nodeCount++;
        currentNode = currentNode->next;
    }

    return (nodeCount);
}
