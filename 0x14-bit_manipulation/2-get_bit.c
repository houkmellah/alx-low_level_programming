#include "main.h"
/**
* get_bit - Fetches bit value at an index in a decimal number.
* @n: Target number.
* @index: Index of bit.
* Return: Value of the bit.
*/
int get_bit(unsigned long int num, unsigned int idx){
if(idx>63)return(-1);
int bitValue=(num>>idx)&1;
return(bitValue);
}
