#include "main.h"
#include <stdlib.h>

/**
 * create_array - Create an array of size "size" and assign char "c".
 * @size: The size of the array.
 * @c: The char to assign to each element.
 *
 * Description: This function creates an array of size "size" and assigns the
 * char "c" to each element.
 *
 * Return: Pointer to the array, or NULL if allocation fails.
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
