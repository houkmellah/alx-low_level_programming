#include "main.h"

/**
 * fetch_bit - retrieves the value of a bit at a specific pos in a dec num
 * @number: number under examination
 * @position: position of the desired bit
 *
 * Return: the value of the targeted bit
 */
int fetch_bit(unsigned long int number, unsigned int position)
{
int target_bit;

if (position > 63)
return (-1);

target_bit = (number >> position) & 1;

return (target_bit);
}
