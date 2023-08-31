#include "main.h"
/**
* set_bit - Sets a bit at an index to 1.
* @n: Pointer to target number.
* @index: Bit index to set.
* Return: 1 if successful, -1 otherwise.
*/
int set_bit(unsigned long int *num, unsigned int idx){
if(idx>63)return(-1);
*num=((1UL<<idx)|*num);
return(1);
}
