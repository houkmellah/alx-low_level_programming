#include "lists.h"

/**
 * reverse_listint - inverts a singly linked list
 * @head: reference to the starting node of the list
 *
 * Return: reference to the first node in the inverted list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *previousNode = NULL;
    listint_t *nextNode = NULL;

    while (*head)
    {
        nextNode = (*head)->next;
        (*head)->next = previousNode;
        previousNode = *head;
        *head = nextNode;
    }

    *head = previousNode;

    return (*head);
}
