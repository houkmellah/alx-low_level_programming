#include "lists.h"

/**
* free_listint2 - releases a singly linked list from memory and sets head to NULL
* @head: reference to the listint_t list to be released
*/
void free_listint2(listint_t **head)
{
listint_t *nextNode;

if (head == NULL)
return;

while (*head)
{
nextNode = (*head)->next;
free(*head);
*head = nextNode;
}

*head = NULL;
}
