#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: Array to iterate over.
 * @size: Number of elements in the array.
 * @action: Pointer to the function to be used on each element.
 * 
 * Return: None.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int idx;

	if (array == NULL || action == NULL)
		return;

	for (idx = 0; idx < size; idx++)
	{
		action(array[idx]);
	}
}
