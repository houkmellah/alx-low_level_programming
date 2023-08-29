#include "lists.h"

/**
 * find_listint_loop - identifies a loop in a linked list
 * @head: start of the linked list to inspect
 *
 * Return: address of the start node of the loop, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *runner1 = head;
    listint_t *runner2 = head;

    if (!head)
        return (NULL);

    while (runner1 && runner2 && runner2->next)
    {
        runner2 = runner2->next->next;
        runner1 = runner1->next;
        if (runner2 == runner1)
        {
            runner1 = head;
            while (runner1 != runner2)
            {
                runner1 = runner1->next;
                runner2 = runner2->next;
            }
            return (runner2);
        }
    }

    return (NULL);
}
