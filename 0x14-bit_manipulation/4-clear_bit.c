#include "main.h"
/**
* clear_bit - Sets bit at index to 0.
* @n: Pointer to target number.
* @index: Index of bit to clear.
* Return: 1 if successful, -1 otherwise.
*/
int clear_bit(unsigned long int *num, unsigned int idx){
if(idx>63)return(-1);
*num=(~(1UL<<idx)&*num);
return(1);
}
