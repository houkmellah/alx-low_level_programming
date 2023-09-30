#include "main.h"

/**
 * get_endianness - determines if a system uses little or big endian
 * Return: 0 for big endian, 1 for little endian
 */
int get_endianness(void)
{
unsigned int indicator = 1;
char *byte_ptr = (char *) &indicator;

return (*byte_ptr);
}
