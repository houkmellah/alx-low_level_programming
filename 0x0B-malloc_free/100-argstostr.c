#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all command-line arguments into a single string.
 * @ac: The number of command-line arguments (argc).
 * @av: The double pointer to the array of command-line arguments (argv).
 *
 * Return: A pointer to the concatenated string, or NULL if allocation fails
 *         or if ac is 0 or av is NULL.
 */
char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}
	l += ac;

	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[r] = av[i][n];
			r++;
		}
		if (str[r] == '\0')
		{
			str[r++] = '\n';
		}
	}

	return (str);
}
