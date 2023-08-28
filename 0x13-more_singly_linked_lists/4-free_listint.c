#include "lists.h"

/**
* free_listint - releases a singly linked list from memory
* @head: listint_t list to be released
*/
void free_listint(listint_t *head)
{
listint_t *nextNode;

while (head)
{
nextNode = head->next;
free(head);
head = nextNode;
}
}
