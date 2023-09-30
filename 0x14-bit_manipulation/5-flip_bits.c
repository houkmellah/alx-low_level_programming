#include "main.h"

/**
* count_flip_bits - determines the number of bits needed to modify  
* to transform one number into another
* @first_num: initial number
* @second_num: target number
*
* Return: number of bits needed to change
*/
unsigned int count_flip_bits(unsigned long int first_num, unsigned long int second_num)
{
int position, change_count = 0;
unsigned long int bit_check;
unsigned long int xor_result = first_num ^ second_num;

for (position = 63; position >= 0; position--)
{
bit_check = xor_result >> position;
if (bit_check & 1)
change_count++;
}

return (change_count);
}
