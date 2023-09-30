#include "main.h"

/**
 * clear_bit - changes a bit at a specified position to 0
 * @n: pointer to the number to be modified
 * @index: position of the bit to be reset
 *
 * Return: 1 if successful, -1 if unsuccessful
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = (~(1UL << index) & *n);
return (1);
}
