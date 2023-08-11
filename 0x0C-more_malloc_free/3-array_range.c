#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @start: start of integer range
 * @end: end of integer range
 * Return: pointer to the new array
 */
int *array_range(int start, int end)
{
int *intArray;
int index, arraySize;

if (start > end)
    return (NULL);

arraySize = end - start + 1;

intArray = malloc(sizeof(int) * arraySize);

if (!intArray)
    return (NULL);

for (index = 0; start <= end; index++)
    intArray[index] = start++;

return (intArray);
}
