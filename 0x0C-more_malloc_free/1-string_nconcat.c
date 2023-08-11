#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates n bytes of one string to another string.
 * @s1: String to which to append.
 * @s2: String to concatenate from.
 * @n: Number of bytes from s2 to concatenate to s1.
 *
 * Return: Pointer to concatenated string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0;
	char *concat;

	if (s1 != NULL)
		while (s1[len1])
			len1++;

	if (s2 != NULL)
		while (s2[len2])
			len2++;

	if (n >= len2)
		n = len2;

	concat = malloc(sizeof(char) * (len1 + n + 1));

	if (concat == NULL)
		return (NULL);

	for (unsigned int i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (unsigned int i = 0; i < n; i++)
		concat[len1 + i] = s2[i];

	concat[len1 + n] = '\0';

	return (concat);
}
