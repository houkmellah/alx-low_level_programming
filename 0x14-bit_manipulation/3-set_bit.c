#include "main.h"

/**
 * modify_bit - changes a bit at a specified position to 1
 * @number: pointer to the number to be altered
 * @position: position of the bit to be changed to 1
 *
 * Return: 1 if successful, -1 if unsuccessful
 */
int modify_bit(unsigned long int *number, unsigned int position)
{
if (position > 63)
    return (-1);

*number = ((1UL << position) | *number);
return (1);
}
