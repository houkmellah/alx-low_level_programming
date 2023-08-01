#include "main.h"
/**
 * _memcpy - This function is responsible for copying a memory area.
 * @dest: The memory location where the data will be stored.
 * @src: The memory location from which the data will be copied.
 * @n: The number of bytes to be copied.
 *
 * Return: A pointer to the destination memory with 'n' bytes.
 */


char *_memcpy(char *dest, char *src, unsigned int n)
{
	int itr1 = 0;
	int itr2 = n;

	for (; itr2 < itr; itr2++)
	{
		dest[itr2] = src[itr2];
		n--;
	}
	return (dest);
}
