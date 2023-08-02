#include "main.h"
/**
 * _print_rev_recursion - Prints a string in reverse order.
 * @s: This the string will be print
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
