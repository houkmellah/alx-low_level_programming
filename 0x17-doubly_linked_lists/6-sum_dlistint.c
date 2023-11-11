#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all data  in a doubly linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The sum of all integer data in the list.
 */
int sum_dlistint(dlistint_t *head)
{
int totalSum = 0;

while (head)
{
totalSum += head->n;
head = head->next;
}
return (totalSum);
}
