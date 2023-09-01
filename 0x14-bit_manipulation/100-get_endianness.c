#include "main.h"
/**
 * get_endianness - Determines the endianness of the machine.
 * Return: 0 if big-endian, 1 if little-endian.
 */
int get_endianness(void)
{
unsigned int val = 1;
char *ptr = (char *)&val;

return (*ptr);
}
