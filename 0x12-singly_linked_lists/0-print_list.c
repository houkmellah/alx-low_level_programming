#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to measure
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int length = 0;

	if (!s)
		return (0);
	while (*s++)
		length++;
	return (length);
}

/**
 * print_list - prints a linked list
 * @h: pointer to the first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t nodes_count = 0;

	while (h)
	{
		printf("[%d] %s\n", _strlen(h->str), h->str ? h->str : "(nil)");
		h = h->next;
		nodes_count++;
	}
	return (nodes_count);
}
