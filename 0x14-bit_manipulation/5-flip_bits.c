#include "main.h"
/**
 * flip_bits - Counts bits to flip to convert one number to another.
 * @n: First number.
 * @m: Second number.
 * Return: Number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int i, bitCount = 0;
unsigned long int temp, xorResult = n ^ m;
for (i = 63; i >= 0; i--)
{
temp = xorResult >> i;
if (temp & 1)
bitCount++;
}
return (bitCount);
}
