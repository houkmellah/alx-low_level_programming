#include "lists.h"

/**
 * add_nodeint_end - appends a node at the end of a singly linked list
 * @head: reference to the first node in the list
 * @n: value to insert in the new node
 *
 * Return: reference to the new node, or NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *newNode;
    listint_t *lastNode = *head;

    newNode = malloc(sizeof(listint_t));
    if (!newNode)
        return (NULL);

    newNode->n = n;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return (newNode);
    }

    while (lastNode->next)
        lastNode = lastNode->next;

    lastNode->next = newNode;

    return (newNode);
}
