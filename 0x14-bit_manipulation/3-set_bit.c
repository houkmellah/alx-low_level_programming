#include "main.h"
/**
 * set_bit - Sets the value of a bit at a specified index to 1.
 * @n: Pointer to the number.
 * @index: Bit index.
 * Return: 1 on success, -1 on failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);
*n = (1UL << index) | *n;
return (1);
}
