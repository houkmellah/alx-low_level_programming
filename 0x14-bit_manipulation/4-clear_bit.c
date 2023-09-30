#include "main.h"

/**
 * reset_bit - changes a bit at a specified position to 0
 * @number: pointer to the number to be modified
 * @position: position of the bit to be reset
 *
 * Return: 1 if successful, -1 if unsuccessful
 */
int reset_bit(unsigned long int *number, unsigned int position)
{
if (position > 63)
return (-1);

*number = (~(1UL << position) & *number);
return (1);
}
