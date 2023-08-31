#include "main.h"
/**
* flip_bits - Counts bits to flip to convert one number to another.
* @n: First number.
* @m: Second number.
* Return: Count of bits to flip.
*/
unsigned int flip_bits(unsigned long int num1, unsigned long int num2){
int i,bitCount=0;
unsigned long int currBit, xorRes=num1^num2;
for(i=63;i>=0;i--){
currBit=xorRes>>i;
if(currBit&1)
bitCount++;
}
return(bitCount);
}
