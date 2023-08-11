#include <stdlib.h>
#include "main.h"
/**
 * *_realloc - reallocates a memory block
 * @oldMemory: memory previously allocated
 * @oldSize: size of oldMemory
 * @newSize: size of new memory bl
 * Return: pointer to the new memory block
 */
void *_realloc(void *oldMemory, unsigned int oldSize, unsigned int newSize)
{
char *newMemory;
char *tempMemory;
unsigned int index;
if (newSize == oldSize)
return (oldMemory);
if (newSize == 0 && oldMemory)
{
free(oldMemory);
return (NULL);
}
if (!oldMemory)
return (malloc(newSize));
newMemory = malloc(newSize);
if (!newMemory)
return (NULL);
tempMemory = oldMemory;
if (newSize < oldSize)
{
for (index = 0; index < newSize; index++)
newMemory[index] = tempMemory[index];
}
if (newSize > oldSize)
{
for (index = 0; index < oldSize; index++)
newMemory[index] = tempMemory[index];
}
free(oldMemory);
return (newMemory);
}
