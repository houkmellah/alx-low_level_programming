#include "main.h"
/**
 * _strstr - Locate the first occurrence of 'needle' in 'haystack'.
 * @haystack: The input string to be searched.
 * @needle: The substring to be found.
 *
 * Return: Pointer to the first occurrence in 'haystack', or 0 if not found.
 */
char *_strstr(char *haystack, char *needle)
{
for (; *haystack != '\0'; haystack++)
{
char *current = haystack;
char *pattern = needle;

while (*current == *pattern && *pattern != '\0')
{
current++;
pattern++;
}

if (*pattern == '\0')
return (haystack);
}

return (0);
}
