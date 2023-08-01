#include "main.h"
/**
 * _strspn - Calculates the length of the initial segment of 's' that consists
 *           of characters present in 'accept'.
 * @s: The input string to be checked.
 * @accept: The set of characters to compare against.
 *
 * Return: The length of the initial segment of 's' containing 'accept' characters.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int length = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				length++;
				break;
			}
			else if (accept[index + 1] == '\0')
				return (length);
		}
		s++;
	}
	return (length);
}
