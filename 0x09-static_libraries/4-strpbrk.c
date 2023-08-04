#include "main.h"
/**
 * _strpbrk - Find the first occurrence of any character from 'accept' in 's'.
 * @s: The input string to be searched.
 * @accept: The set of characters to search for.
 *
 * Return: Pointer to the first occurrence in 's', or NULL if none found.
 */
char *_strpbrk(char *s, char *accept)
{
int index;

while (*s)
{
for (index = 0; accept[index]; index++)
{
if (*s == accept[index])
return (s);
}
s++;
}
return ('\0');
}
