#include "main.h"
/**
 * _strchr - Searches for the first occurrence of a character in a string.
 * @s: The input string to be searched.
 * @c: The character to find in the string.
 *
 * Return: Pointer to the first occurrence of 'c' in 's', or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	int itr = 0;

	for (; s[itr] >= '\0'; itr++)
	{
		if (s[itr] == c)
			return (&s[itr]);
	}
	return (0);
}
