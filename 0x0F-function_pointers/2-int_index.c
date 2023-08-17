#include "function_pointers.h"

/**
 * int_index - Returns the index of the first el for which the comparison.
 * @array: Array to search through.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the comparison function.
 *
* Return: Index of the first matching element, or -1 if no match or error.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int idx;

	if (array == NULL || size <= 0 || cmp == NULL)
		return (-1);

	for (idx = 0; idx < size; idx++)
	{
		if (cmp(array[idx]))
			return (idx);
	}
	return (-1);
}
