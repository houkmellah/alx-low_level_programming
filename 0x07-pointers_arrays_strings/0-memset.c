#include "main.h"

/**
* _memset - This function to filling a block of memory with a specific value.
* @s: The starting address of the memory to be filled.
* @b: The desired value to fill the memory with.
* @n: The number of bytes to be changed.
*
* Return: A pointer to the modified memory block.
*/

char *_memset(char *s, char b, unsigned int n)
{
	int a = 0;

	for (; n > 0; a++)
	{
		s[a] = b;
		n--;
	}
	return (s);
}
