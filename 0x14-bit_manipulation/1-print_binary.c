#include "main.h"

/**
 * display_binary - displays the binary representation of a decimal number
 * @value: number to be displayed in binary
 */
void print_binary(unsigned long int value)
{
int position, counter = 0;
unsigned long int currentBit;

for (position = 63; position >= 0; position--)
{
currentBit = value >> position;

if (currentBit & 1)
{
_putchar('1');
counter++;
}
else if (counter)
_putchar('0');
}
if (!counter)
_putchar('0');
}
