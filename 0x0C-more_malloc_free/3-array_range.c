#include <stdlib.h>
#include "main.h"

/**
* *_memset - fills memory with a constant byte
* @memArea: area to fill
* @value: value to set
* @count: times to set value
*
* Return: pointer to the filled area
*/
char *_memset(char *memArea, char value, unsigned int count)
{
unsigned int index;
for (index = 0; index < count; index++)
{
memArea[index] = value;
}
return (memArea);
}

/**
* *_calloc - allocates memory for an array
* @numElem: number of array elements
* @elemSize: size of each element
*
* Return: pointer to allocated memory
*/
void *_calloc(unsigned int numElem, unsigned int elemSize)
{
char *allocatedMem;
if (numElem == 0 || elemSize == 0)
return (NULL);
allocatedMem = malloc(elemSize * numElem);
if (allocatedMem == NULL)
return (NULL);
_memset(allocatedMem, 0, numElem * elemSize);
return (allocatedMem);
}
