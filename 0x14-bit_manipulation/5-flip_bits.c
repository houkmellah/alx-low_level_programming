#include "main.h"

/**
* flip_bits - determines the number of bits needed to modify
* to transform one number into another
* @n: initial number
* @m: target number
*
* Return: number of bits needed to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int position, change_count = 0;
unsigned long int bit_check;
unsigned long int xor_result = n ^ m;

for (position = 63; position >= 0; position--)
{
bit_check = xor_result >> position;
if (bit_check & 1)
change_count++;
}

return (change_count);
}
