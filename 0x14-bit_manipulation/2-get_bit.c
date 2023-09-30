#include "main.h"

/**
 * get_bit - retrieves the value of a bit at a specific pos in a dec num
 * @number: number under examination
 * @position: position of the desired bit
 *
 * Return: the value of the targeted bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
int target_bit;

if (index > 63)
return (-1);

target_bit = (n >> index) & 1;

return (target_bit);
}
