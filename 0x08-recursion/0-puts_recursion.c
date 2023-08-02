#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - function send the same result like  puts();
 * @s: input char
 * Return: Always 0 (if is Success)
 */
void _puts_recursion(char *s)
{
if (*s)
{
_putchar(*s);
_puts_recursion(s + 1);
}
else
_putchar('\n');
}
