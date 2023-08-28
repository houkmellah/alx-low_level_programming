#include "lists.h"

/**
 * pop_listint - removes the first node of a singly linked list
 * @head: reference to the first node in the list
 *
 * Return: the value inside the node that was removed,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
    listint_t *nextNode;
    int dataValue;

    if (!head || !*head)
        return (0);

    dataValue = (*head)->n;
    nextNode = (*head)->next;
    free(*head);
    *head = nextNode;

    return (dataValue);
}
